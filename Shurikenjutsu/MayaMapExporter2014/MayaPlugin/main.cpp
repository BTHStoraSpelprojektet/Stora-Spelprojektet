#include <stdio.h>
#include <cstdio>
#include <tchar.h>
#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include <fstream>
#include <cmath>
//#define OPENMAYA_EXPORT

#include <maya/MIOStream.h>
#include <maya/MGlobal.h>
#include <maya/MString.h>
#include <maya/MStringArray.h>
#include <maya/MEventMessage.h>
#include <maya/MFnPlugin.h>
#include <maya/MSelectionList.h>
#include <maya/MFnTransform.h>
#include <maya/MDagPath.h>
#include <maya/MVector.h>
#include <maya/MFnMesh.h>
#include <maya/MFloatArray.h>
#include <maya/MPointArray.h>
#include <maya/MFloatVectorArray.h>
#include <maya/MItMeshPolygon.h>
#include <maya/MFnCamera.h>
#include <maya/MPxCommand.h>
#include <maya/MSyntax.h>
#include <maya/MArgDatabase.h>
#include <maya/MMatrix.h>
#include <maya/MUiMessage.h>
#include <maya/MNodeMessage.h>
#include <maya/MPlugArray.h>
#include <maya/MFnLambertShader.h>
#include <maya/MDGMessage.h>
#include <maya/MCallbackIdArray.h>
#include <maya/MFileObject.h>
#include <maya/MImageFileInfo.h>
#include <maya/MFnStringData.h>
#include <maya/MPolyMessage.h>
#include <maya/MDagMessage.h>
#include <maya/MItDependencyNodes.h>
#include <maya/MFileIO.h>
#include <maya/MEulerRotation.h>
#include <maya/MFloatPointArray.h>

static const int NUMOFWORLDOBJECTS = 4096;

struct worldObject{
	std::string name;
	double x, y, z;
	double rotatex, rotatey, rotatez, rotatew;
};

struct worldMap{
	worldObject wObjects[NUMOFWORLDOBJECTS];
	worldObject wBoundingBox[NUMOFWORLDOBJECTS];
};

worldMap world;
MString loadPath;
int counter = 0;
int boundingboxcounter = 0;
std::vector<MVector> points;

class MapExporter : public MPxCommand
{
public:
	MapExporter();
	virtual                 ~MapExporter();
	
	//MStatus                 doIt( const MArgList& args );
	static MStatus doIt();

    static MSyntax newSyntax();
    static void* creator();

	static void print(MString string);
	static void print(int number);
	static void print(float number);
	static void print(double number);
	MStatus initializePlugin(MObject obj);
	static void GetPositions();
	static void WriteToFile();
	


private:
	MStatus createEvent(MString eventName, MMessage::MBasicFunction eventCB, int);
    MStringArray events;
};


//
// Command class implementation
//

// Constructor
//
MapExporter::MapExporter()
{
	
    events.clear();
}

// Destructor
//
MapExporter::~MapExporter()
{
	
}

// creator
//
void* MapExporter::creator()
{
	return (void *)(new MapExporter);
}

// newSyntax
//
MSyntax MapExporter::newSyntax()
{
        MSyntax syntax;

        return syntax;
}


/*MStatus eventTest::createEvent(MString eventName, MMessage::MBasicFunction eventCB, int index){
	
	MStatus status;
	MCallbackId cid = MEventMessage::addEventCallback(
                                eventName,
                                eventCB,
                                NULL,
                                &status);
	callbackIdList.append( cid );
	
    if (!status)
    {
        status.perror("failed to add callback for DragRelease");
		callbackIdList.remove(cid);
    }
	return status;
}*/


void MapExporter::print(MString string)
{
	MGlobal::displayInfo(string);
}

void MapExporter::print(int number)
{
	char c[50];
	sprintf(c, "%.3f", number);
	
	MGlobal::displayInfo(c);
}

void MapExporter::print(float number)
{
	char c[50];
	sprintf(c, "%.3f", number);

	MGlobal::displayInfo(c);
}

void MapExporter::print(double number)
{
	char c[50];
	sprintf(c, "%.3f", number);

	MGlobal::displayInfo(c);
}

void MapExporter::GetPositions(){
	print("GetPositions");
	MItDependencyNodes it(MFn::kInvalid);


	while (!it.isDone())
	{

		//print("it");
		// get a handle to this node
		MObject obj = it.item();

		// write the node type found


		if (obj.apiType() == MFn::kTransform){
			MFnTransform transform(obj);
			for (unsigned int i = 0; i < transform.childCount(); i++)
			{
				if (transform.child(i).apiType() == MFn::kMesh){
					print(transform.name());
					MFnMesh mesh(transform.child(i));
					MVector v = transform.getTranslation(MSpace::kTransform);
					double dest2[3];
					v.get(dest2);
					//MMatrix matrix = mesh.transformationMatrix();

					double rotatex, rotatey, rotatez, rotatew;
					//transform.getRotationQuaternion(rotatex, rotatey, rotatez, rotatew, MSpace::kTransform);
					
					MEulerRotation meuler;
					transform.getRotation(meuler);
					MVector eulerRotation=meuler.asVector();
					rotatex = eulerRotation.x;
					rotatey = eulerRotation.y;
					rotatez = eulerRotation.z;
					rotatew = 0;

					print(dest2[0]);
					print(dest2[1]);
					print(dest2[2]);
					
					std::string str = transform.name().asChar();
					
					if (str.find("LevelBoundingBox") != std::string::npos){
						world.wBoundingBox[boundingboxcounter].name = transform.name().asChar();
						world.wBoundingBox[boundingboxcounter].x = dest2[0];
						world.wBoundingBox[boundingboxcounter].y = dest2[1];
						world.wBoundingBox[boundingboxcounter].z = dest2[2];

						world.wBoundingBox[boundingboxcounter].rotatex = rotatex;
						world.wBoundingBox[boundingboxcounter].rotatey = rotatey;
						world.wBoundingBox[boundingboxcounter].rotatez = rotatez;
						world.wBoundingBox[boundingboxcounter].rotatew = rotatew;

						/*MIntArray mintarray;
						MIntArray vertexList;
						mesh.getVertices(mintarray, vertexList);
						Mit

						MPointArray mPointArray;
						mesh.getPoints(mPointArray, MSpace::kTransform);
						mesh.getPoint()
						int length = mPointArray.length();

						double* test[4];
						double  dest[100][4];
						mPointArray.get(dest);*/

						MFloatPointArray tempPoints;
						mesh.getPoints(tempPoints, MSpace::kObject);

						/*for (int j = 0; j < tempPoints.length(); j++)
						{
						char ch[128];
						sprintf(ch, "%.5f %.5f %.5f", tempPoints[j].x, tempPoints[j].y, tempPoints[j].z);
						MGlobal::displayInfo(ch);
						}*/
						//MVector tempVec(tempPoints[vtxIndex].x, tempPoints[vtxIndex].y, tempPoints[vtxIndex].z);


						MDagPath md;
						mesh.getPath(md);
						MStatus stat;

						MItMeshPolygon polyIter(md, MObject::kNullObj, &stat);
						for (; !polyIter.isDone(); polyIter.next())
						{
							if (polyIter.currentItem().apiType() == MFn::kMeshPolygonComponent)
							{
								int polyVtxCount = polyIter.polygonVertexCount();
								for (int vtx = 0; vtx < polyVtxCount; vtx++)
								{
									//if (mesh.numUVs() > 0)
									//{
									/*int uvIndex;
									int vtxIndex, normIndex, tangIndex;

									polyIter.getUVIndex(vtx, uvIndex);
									vtxIndex = polyIter.vertexIndex(vtx);
									normIndex = polyIter.normalIndex(vtx);
									tangIndex = polyIter.tangentIndex(vtx);

									int fdh = tempU.length();
									int sdg = tempPoints.length();*/

									int vtxIndex;
									vtxIndex = polyIter.vertexIndex(vtx);
									MVector tempVec(tempPoints[vtxIndex].x, tempPoints[vtxIndex].y, tempPoints[vtxIndex].z);
									points.push_back(tempVec);

									/*char ch[128];
									sprintf(ch, "%.5f %.5f %.5f", tempVec.x, tempVec.y, tempVec.z);
									MGlobal::displayInfo(ch);*/

									/*tempVec = MVector(tempNormals[normIndex].x, tempNormals[normIndex].y, tempNormals[normIndex].z);
									m_Data.normals.push_back(tempVec);
									tempVec = MVector(tempTangents[tangIndex].x, tempTangents[tangIndex].y, tempTangents[tangIndex].z);
									m_Data.tangents.push_back(tempVec);*/

									/*m_Data.u.push_back(1 - tempV[uvIndex]);
									m_Data.v.push_back(tempU[uvIndex]);*/
									//}
								}
							}
						}
						print("LALALA");
						char cha[128];

						//TODO fixa ordningen på width (lengthX), height (lengthY), depth (lengthZ)
						float lengthX = points[0].x;
						float lengthY = points[0].y;
						float lengthZ = points[0].z;
						sprintf(cha, "%.5f %.5f %.5f", lengthX, lengthY, lengthZ);
						MGlobal::displayInfo(cha);
						boundingboxcounter++;
					}
					else{

						world.wObjects[counter].name = transform.name().asChar();
						world.wObjects[counter].x = dest2[0];
						world.wObjects[counter].y = dest2[1];
						world.wObjects[counter].z = dest2[2];

						world.wObjects[counter].rotatex = rotatex;
						world.wObjects[counter].rotatey = rotatey;
						world.wObjects[counter].rotatez = rotatez;
						world.wObjects[counter].rotatew = rotatew;

					}

					
					
					

					/*float dest[4][4];
					print(matrix.get(dest));
					print(dest[0][0]);
					print(dest[0][1]);
					print(dest[0][2]);
					print(dest[0][3]);
					print(dest[1][0]);
					print(dest[1][1]);
					print(dest[1][2]);
					print(dest[1][3]);
					print(dest[2][0]);
					print(dest[2][1]);
					print(dest[2][2]);
					print(dest[2][3]);
					print(dest[3][0]);
					print(dest[3][1]);
					print(dest[4][2]);
					print(dest[3][3]);*/
					counter++;
				}
				if (transform.child(i).apiType() == MFn::kLocator){
					print(transform.name());
					MFnMesh mesh(transform.child(i));
					MVector v = transform.getTranslation(MSpace::kTransform);
					double dest2[3];
					v.get(dest2);
					//MMatrix matrix = mesh.transformationMatrix();

					double rotatex, rotatey, rotatez, rotatew;
					//transform.getRotationQuaternion(rotatex, rotatey, rotatez, rotatew, MSpace::kTransform);

					MEulerRotation meuler;
					transform.getRotation(meuler);
					MVector eulerRotation = meuler.asVector();
					rotatex = eulerRotation.x;
					rotatey = eulerRotation.y;
					rotatez = eulerRotation.z;
					rotatew = 0;

					print(dest2[0]);
					print(dest2[1]);
					print(dest2[2]);

					world.wObjects[counter].name = transform.name().asChar();
					world.wObjects[counter].x = dest2[0];
					world.wObjects[counter].y = dest2[1];
					world.wObjects[counter].z = dest2[2];

					world.wObjects[counter].rotatex = rotatex;
					world.wObjects[counter].rotatey = rotatey;
					world.wObjects[counter].rotatez = rotatez;
					world.wObjects[counter].rotatew = rotatew;

					counter++;
				}

			} 

			/*if (obj.apiType() == MFn::kMesh){
				MFnMesh mesh(obj);
				MFnTransform transform(mesh.parent(0));
				//MFnTransform transform2(transform.parent(0));
				print(mesh.name());
				print(transform.name());
				MMatrix matrix = transform.transformationMatrix();


				print(transform.translation(MSpace::kTransform).x);
				print(transform.translation(MSpace::kWorld).y);
				print(transform.translation(MSpace::kObject).z);

			}*/
		}
		

		// move on to next node
		it.next();
	}
}

void MapExporter::WriteToFile(){
	print("WriteToFile");
	MString path = MFileIO::currentFile();
	
	MStringArray mstrArr;
	path.split('/', mstrArr);
	MString filenameWithExtension = mstrArr[mstrArr.length() - 1];
	print(filenameWithExtension);

	MStringArray mstrArr2;
	filenameWithExtension.split('.', mstrArr2);
	MString filenameWithoutExtension = mstrArr2[mstrArr2.length() - 2];
	print(filenameWithoutExtension);

	std::wstring string;
	string.append(loadPath.asWChar());
	string.append(L"/Levels/");
	string.append(filenameWithoutExtension.asWChar());
	string.append(L".SSPL");
	MString filenameWithLevelFormat(string.c_str());
	print(loadPath);
	print(filenameWithLevelFormat);

	
	std::ofstream outfile(filenameWithLevelFormat.asChar());

	//Maps size, object positions, 
	outfile << "Map size: 100 100" << "\n";
	outfile << "Number of objects: " << counter << "\n";
	outfile << "Number of bounding boxes: " << boundingboxcounter << "\n";
	
	for (int i = 0; i < boundingboxcounter; i++){
		if (strcmp(world.wBoundingBox[i].name.c_str(), "") != 0){
			outfile << "" << world.wBoundingBox[i].name.c_str() << " " << world.wBoundingBox[i].x << " " << world.wBoundingBox[i].y << " " << world.wBoundingBox[i].z << " " << world.wBoundingBox[i].rotatex << " " << world.wBoundingBox[i].rotatey << " " << world.wBoundingBox[i].rotatez << " ";
			outfile << "" << std::abs(points[i].x) << " " << std::abs(points[i].y) << " " << std::abs(points[i].z) << "\n";
		}
	}
	
	
	for (int i = 0; i < counter; i++)
	{
		if (strcmp(world.wObjects[i].name.c_str(), "") != 0){
			outfile << "" << world.wObjects[i].name.c_str() << " " << world.wObjects[i].x << " " << world.wObjects[i].y << " " << world.wObjects[i].z << " " << world.wObjects[i].rotatex << " " << world.wObjects[i].rotatey << " " << world.wObjects[i].rotatez << "\n";
		}
	}

	outfile.close();
}

// doIt
//
//MStatus MapExporter::doIt(const MArgList& args)
MStatus MapExporter::doIt()
{
        MStatus status;
		//MCallbackId cid;

		print("INIT");

		GetPositions();
		WriteToFile();

        return status;
}

//
// Plug-in functions
//

MStatus initializePlugin(MObject obj)
{ 
        MStatus   status;
        MFnPlugin plugin( obj, PLUGIN_COMPANY, "3.0", "Any");	
		loadPath = plugin.loadPath(&status);
        /*status = plugin.registerCommand("eventTest",
                                                                        MapExporter::creator,
																		MapExporter::newSyntax);*/


        /*if (!status)
        {
                status.perror("registerCommand");
        }*/

		
		
		MapExporter::doIt();

        return status;
}

MStatus uninitializePlugin( MObject obj)
{
        MStatus   status;
        MFnPlugin plugin( obj );

		//MMessage::removeCallbacks(callbackIdList);
		//callbackIdList.clear();
		
        return status;
}

	
//
// Callback function
//


void createMesh(MFnTransform& mTrans, MFnMesh& mMesh, bool firstCreation = false){

}




	//DagObjectCreated
	//
	// linearUnitChanged     yes
 // 
// timeUnitChanged       yes
 // 
// angularUnitChanged    yes
 // 
// Undo                  yes
 // 
// undoSupressed         yes
 // 
// Redo                  yes
 // 
// timeChanged           yes
 // 
// currentContainerChange  yes
 // 
// quitApplication       yes
 // 
// RecentCommandChanged  yes
 // 
// ToolChanged           yes
 // 
// PostToolChanged       yes
 // 
// ToolDirtyChanged      yes
 // 
// DisplayRGBColorChanged  yes
 // 
// animLayerRebuild      yes
 // 
// animLayerRefresh      yes
 // 
// animLayerAnimationChanged  yes
 // 
// animLayerLockChanged  yes
 // 
// animLayerBaseLockChanged  yes
 // 
// animLayerGhostChanged  yes
 // 
// cameraChange          yes
 // 
// cameraDisplayAttributesChange  yes
 // 
// SelectionChanged      yes
 // 
// LiveListChanged       yes
 // 
// ActiveViewChanged     yes
 // 
// SelectModeChanged     yes
 // 
// SelectTypeChanged     yes
 // 
// SelectPreferenceChanged  yes
 // 
// DisplayPreferenceChanged  yes
 // 
// DagObjectCreated      yes
 // 
// renderLayerManagerChange  yes
 // 
// renderLayerChange     yes
 // 
// displayLayerManagerChange  yes
 // 
// displayLayerAdded     yes
 // 
// displayLayerDeleted   yes
 // 
// displayLayerVisibilityChanged  yes
 // 
// displayLayerChange    yes
 // 
// renderPassChange      yes
 // 
// renderPassSetChange   yes
 // 
// renderPassSetMembershipChange  yes
 // 
// passContributionMapChange  yes
 // 
// DisplayColorChanged   yes
 // 
// lightLinkingChanged   yes
 // 
// lightLinkingChangedNonSG  yes
 // 
// UvTileProxyDirtyChangeTrigger  yes
 // 
// polyTopoSymmetryValidChanged  yes
 // 
// SceneSegmentChanged   yes
 // 
// PostSceneSegmentChanged  yes
 // 
// SequencerActiveShotChanged  yes
 // 
// ColorIndexChanged     yes
 // 
// deleteAll             yes
 // 
// NameChanged           yes
 // 
// symmetricModellingOptionsChanged  yes
 // 
// softSelectOptionsChanged  yes
 // 
// SetModified           yes
 // 
// linearToleranceChanged  yes
 // 
// angularToleranceChanged  yes
 // 
// nurbsToPolygonsPrefsChanged  yes
 // 
// nurbsCurveRebuildPrefsChanged  yes
 // 
// constructionHistoryChanged  yes
 // 
// threadCountChanged    yes
 // 
// SceneSaved            yes
 // 
// NewSceneOpened        yes
 // 
// SceneOpened           yes
 // 
// SceneImported         yes
 // 
// PreFileNewOrOpened    yes
 // 
// PostSceneRead         yes
 // 
// workspaceChanged      yes
 // 
// startColorPerVertexTool  yes
 // 
// stopColorPerVertexTool  yes
 // 
// start3dPaintTool      yes
 // 
// stop3dPaintTool       yes
 // 
// DragRelease           yes
 // 
// ModelPanelSetFocus    yes
 // 
// modelEditorChanged    yes
 // 
// MenuModeChanged       yes
 // 
// gridDisplayChanged    yes
 // 
// interactionStyleChanged  yes
 // 
// axisAtOriginChanged   yes
 // 
// CurveRGBColorChanged  yes
 // 
// SelectPriorityChanged  yes
 // 
// snapModeChanged       yes
 // 
// nurbsToSubdivPrefsChanged  yes
 // 
// ChannelBoxLabelSelected  yes
 // 
// selectionPipelineChanged  yes
 // 
// playbackRangeChanged  yes
 // 
// playbackRangeSliderChanged  yes
 // 
// currentSoundNodeChanged  yes
 // 
// glFrameTrigger        yes
 // 
// RebuildUIValues       yes
 // 
//  // 
// event RecentCommandChanged occurred
