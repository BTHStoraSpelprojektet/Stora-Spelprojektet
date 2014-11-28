import pymel.core as pm
import point

reload(point)
from point import Point
	
class Main():
	def __init__(self):
	
		self.circle(pm.ls('FootL')[0])
		self.circle(pm.ls('FootR')[0])
		self.circle(pm.ls('HandL')[0])
		self.circle(pm.ls('HandR')[0])
		self.triangle(pm.ls('Hip')[0])
		self.square(pm.ls('ElbowL')[0], True, "HandL")
		self.square(pm.ls('ElbowR')[0], True, "HandR")
		self.square(pm.ls('KneeL')[0], False, "FootL")
		self.square(pm.ls('KneeR')[0], False, "FootR")
		
	
	def circle(self, joint):
		a = 0.5
		b = 0.6875
		
		
		p0 = Point(a + 0.1,0 , -a - 0.1)
		p1 = Point(b + 0.2, 0, 0)
		p2 = Point(a + 0.1, 0, a + 0.1)
		p3 = Point(0, 0, b)
		p4 = Point(-a - 0.1, 0, a + 0.1)
		p5 = Point(-b - 0.2, 0, 0)
		p6 = Point(-a - 0.1, 0, -a - 0.1)
		p7 = Point(0, 0, - b)
		
		points = [p0, p1, p2, p3, p4, p5, p6, p7, p0, p1, p2]
		pts = []
		
		for point in points:
			pts.append(point.getPoint())
		
		pm.curve(per = True, d = 3, p = pts, k = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])

		pm.parent("%s" % str(pm.ls(sl = True)[0]), "%s" % str(joint), relative = True)
		pm.parent("%s" % str(pm.ls(sl = True)[0]), world = True)
		curve = "%s" % str(pm.ls(sl = True)[0])
		g = 0
		while g < 8:
			pm.moveVertexAlongDirection(curve + ".cv[" + str(g) + "]", d = [0,1,0], m = -0.2)
			g += 1
			
		group = pm.group(curve)
		
		parent = pm.listRelatives(joint, p = True)
		pm.parentConstraint(parent, group, mo = True)
		pm.orientConstraint(curve, joint)
		handle = joint + "IK"
		pm.pointConstraint(curve, handle)
		
	def triangle(self, joint):
		p0 = Point(-3, 0, -1.5)
		p1 = Point(0, 0, 3)
		p2 = Point(3, 0, -1.5)
		
		points = [p0, p1, p2, p0]
		pts = []
		for point in points:
			pts.append(point.getPoint())
			
		pm.curve(per = True, d = 1, p = pts, k = [0, 1, 2, 3])
		pos = pm.PyNode("%s" % joint).getTranslation()
		pm.move(pos)
		pm.pointConstraint(pm.ls(sl = True)[0], joint)
		
		
	def square(self, joint, arm, side):
		p0 = Point(0, 0.2, -0.2)
		p1 = Point(0, 0.2, 0.2)
		p2 = Point(0, -0.2, 0.2)
		p3 = Point(0, -0.2, -0.2)
		
		points = [p0, p1, p2, p3, p0]
		pts = []
		for point in points:
			pts.append(point.getPoint())
		
		pm.curve(per = True, d = 1, p = pts, k = [0, 1, 2, 3, 4])
		curve = "%s" % str(pm.ls(sl = True)[0])
		pm.parent(curve, "%s" % str(joint), relative = True)
		pm.parent(curve, world = True)
		if arm == True:
			pm.move(-1, moveZ = True)
		if arm == False:
			pm.move(1, moveZ = True)
			pm.makeIdentity(r = True)
		pm.makeIdentity(a = True)
		pm.poleVectorConstraint(curve, side + "IK")
		
main = Main()
		
	