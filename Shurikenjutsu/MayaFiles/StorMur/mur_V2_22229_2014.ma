//Maya ASCII 2014 scene
//Name: mur_V2_22229_2014.ma
//Last modified: Mon, Jan 19, 2015 02:38:44 PM
//Codeset: 1252
requires maya "2014";
requires -nodeType "mentalrayFramebuffer" -nodeType "mentalrayOutputPass" -nodeType "mentalrayRenderPass"
		 -nodeType "mentalrayUserBuffer" -nodeType "mentalraySubdivApprox" -nodeType "mentalrayCurveApprox"
		 -nodeType "mentalraySurfaceApprox" -nodeType "mentalrayDisplaceApprox" -nodeType "mentalrayOptions"
		 -nodeType "mentalrayGlobals" -nodeType "mentalrayItemsList" -nodeType "mentalrayShader"
		 -nodeType "mentalrayUserData" -nodeType "mentalrayText" -nodeType "mentalrayTessellation"
		 -nodeType "mentalrayPhenomenon" -nodeType "mentalrayLightProfile" -nodeType "mentalrayVertexColors"
		 -nodeType "mentalrayIblShape" -nodeType "mapVizShape" -nodeType "mentalrayCCMeshProxy"
		 -nodeType "cylindricalLightLocator" -nodeType "discLightLocator" -nodeType "rectangularLightLocator"
		 -nodeType "sphericalLightLocator" -nodeType "abcimport" -nodeType "mia_physicalsun"
		 -nodeType "mia_physicalsky" -nodeType "mia_material" -nodeType "mia_material_x" -nodeType "mia_roundcorners"
		 -nodeType "mia_exposure_simple" -nodeType "mia_portal_light" -nodeType "mia_light_surface"
		 -nodeType "mia_exposure_photographic" -nodeType "mia_exposure_photographic_rev" -nodeType "mia_lens_bokeh"
		 -nodeType "mia_envblur" -nodeType "mia_ciesky" -nodeType "mia_photometric_light"
		 -nodeType "mib_texture_vector" -nodeType "mib_texture_remap" -nodeType "mib_texture_rotate"
		 -nodeType "mib_bump_basis" -nodeType "mib_bump_map" -nodeType "mib_passthrough_bump_map"
		 -nodeType "mib_bump_map2" -nodeType "mib_lookup_spherical" -nodeType "mib_lookup_cube1"
		 -nodeType "mib_lookup_cube6" -nodeType "mib_lookup_background" -nodeType "mib_lookup_cylindrical"
		 -nodeType "mib_texture_lookup" -nodeType "mib_texture_lookup2" -nodeType "mib_texture_filter_lookup"
		 -nodeType "mib_texture_checkerboard" -nodeType "mib_texture_polkadot" -nodeType "mib_texture_polkasphere"
		 -nodeType "mib_texture_turbulence" -nodeType "mib_texture_wave" -nodeType "mib_reflect"
		 -nodeType "mib_refract" -nodeType "mib_transparency" -nodeType "mib_continue" -nodeType "mib_opacity"
		 -nodeType "mib_twosided" -nodeType "mib_refraction_index" -nodeType "mib_dielectric"
		 -nodeType "mib_ray_marcher" -nodeType "mib_illum_lambert" -nodeType "mib_illum_phong"
		 -nodeType "mib_illum_ward" -nodeType "mib_illum_ward_deriv" -nodeType "mib_illum_blinn"
		 -nodeType "mib_illum_cooktorr" -nodeType "mib_illum_hair" -nodeType "mib_volume"
		 -nodeType "mib_color_alpha" -nodeType "mib_color_average" -nodeType "mib_color_intensity"
		 -nodeType "mib_color_interpolate" -nodeType "mib_color_mix" -nodeType "mib_color_spread"
		 -nodeType "mib_geo_cube" -nodeType "mib_geo_torus" -nodeType "mib_geo_sphere" -nodeType "mib_geo_cone"
		 -nodeType "mib_geo_cylinder" -nodeType "mib_geo_square" -nodeType "mib_geo_instance"
		 -nodeType "mib_geo_instance_mlist" -nodeType "mib_geo_add_uv_texsurf" -nodeType "mib_photon_basic"
		 -nodeType "mib_light_infinite" -nodeType "mib_light_point" -nodeType "mib_light_spot"
		 -nodeType "mib_light_photometric" -nodeType "mib_cie_d" -nodeType "mib_blackbody"
		 -nodeType "mib_shadow_transparency" -nodeType "mib_lens_stencil" -nodeType "mib_lens_clamp"
		 -nodeType "mib_lightmap_write" -nodeType "mib_lightmap_sample" -nodeType "mib_amb_occlusion"
		 -nodeType "mib_fast_occlusion" -nodeType "mib_map_get_scalar" -nodeType "mib_map_get_integer"
		 -nodeType "mib_map_get_vector" -nodeType "mib_map_get_color" -nodeType "mib_map_get_transform"
		 -nodeType "mib_map_get_scalar_array" -nodeType "mib_map_get_integer_array" -nodeType "mib_fg_occlusion"
		 -nodeType "mib_bent_normal_env" -nodeType "mib_glossy_reflection" -nodeType "mib_glossy_refraction"
		 -nodeType "builtin_bsdf_architectural" -nodeType "builtin_bsdf_architectural_comp"
		 -nodeType "builtin_bsdf_carpaint" -nodeType "builtin_bsdf_ashikhmin" -nodeType "builtin_bsdf_lambert"
		 -nodeType "builtin_bsdf_mirror" -nodeType "builtin_bsdf_phong" -nodeType "contour_store_function"
		 -nodeType "contour_store_function_simple" -nodeType "contour_contrast_function_levels"
		 -nodeType "contour_contrast_function_simple" -nodeType "contour_shader_simple" -nodeType "contour_shader_silhouette"
		 -nodeType "contour_shader_maxcolor" -nodeType "contour_shader_curvature" -nodeType "contour_shader_factorcolor"
		 -nodeType "contour_shader_depthfade" -nodeType "contour_shader_framefade" -nodeType "contour_shader_layerthinner"
		 -nodeType "contour_shader_widthfromcolor" -nodeType "contour_shader_widthfromlightdir"
		 -nodeType "contour_shader_widthfromlight" -nodeType "contour_shader_combi" -nodeType "contour_only"
		 -nodeType "contour_composite" -nodeType "contour_ps" -nodeType "mi_metallic_paint"
		 -nodeType "mi_metallic_paint_x" -nodeType "mi_bump_flakes" -nodeType "mi_car_paint_phen"
		 -nodeType "mi_metallic_paint_output_mixer" -nodeType "mi_car_paint_phen_x" -nodeType "physical_lens_dof"
		 -nodeType "physical_light" -nodeType "dgs_material" -nodeType "dgs_material_photon"
		 -nodeType "dielectric_material" -nodeType "dielectric_material_photon" -nodeType "oversampling_lens"
		 -nodeType "path_material" -nodeType "parti_volume" -nodeType "parti_volume_photon"
		 -nodeType "transmat" -nodeType "transmat_photon" -nodeType "mip_rayswitch" -nodeType "mip_rayswitch_advanced"
		 -nodeType "mip_rayswitch_environment" -nodeType "mip_card_opacity" -nodeType "mip_motionblur"
		 -nodeType "mip_motion_vector" -nodeType "mip_matteshadow" -nodeType "mip_cameramap"
		 -nodeType "mip_mirrorball" -nodeType "mip_grayball" -nodeType "mip_gamma_gain" -nodeType "mip_render_subset"
		 -nodeType "mip_matteshadow_mtl" -nodeType "mip_binaryproxy" -nodeType "mip_rayswitch_stage"
		 -nodeType "mip_fgshooter" -nodeType "mib_ptex_lookup" -nodeType "misss_physical"
		 -nodeType "misss_physical_phen" -nodeType "misss_fast_shader" -nodeType "misss_fast_shader_x"
		 -nodeType "misss_fast_shader2" -nodeType "misss_fast_shader2_x" -nodeType "misss_skin_specular"
		 -nodeType "misss_lightmap_write" -nodeType "misss_lambert_gamma" -nodeType "misss_call_shader"
		 -nodeType "misss_set_normal" -nodeType "misss_fast_lmap_maya" -nodeType "misss_fast_simple_maya"
		 -nodeType "misss_fast_skin_maya" -nodeType "misss_fast_skin_phen" -nodeType "misss_fast_skin_phen_d"
		 -nodeType "misss_mia_skin2_phen" -nodeType "misss_mia_skin2_phen_d" -nodeType "misss_lightmap_phen"
		 -nodeType "misss_mia_skin2_surface_phen" -nodeType "surfaceSampler" -nodeType "mib_data_bool"
		 -nodeType "mib_data_int" -nodeType "mib_data_scalar" -nodeType "mib_data_vector"
		 -nodeType "mib_data_color" -nodeType "mib_data_string" -nodeType "mib_data_texture"
		 -nodeType "mib_data_shader" -nodeType "mib_data_bool_array" -nodeType "mib_data_int_array"
		 -nodeType "mib_data_scalar_array" -nodeType "mib_data_vector_array" -nodeType "mib_data_color_array"
		 -nodeType "mib_data_string_array" -nodeType "mib_data_texture_array" -nodeType "mib_data_shader_array"
		 -nodeType "mib_data_get_bool" -nodeType "mib_data_get_int" -nodeType "mib_data_get_scalar"
		 -nodeType "mib_data_get_vector" -nodeType "mib_data_get_color" -nodeType "mib_data_get_string"
		 -nodeType "mib_data_get_texture" -nodeType "mib_data_get_shader" -nodeType "mib_data_get_shader_bool"
		 -nodeType "mib_data_get_shader_int" -nodeType "mib_data_get_shader_scalar" -nodeType "mib_data_get_shader_vector"
		 -nodeType "mib_data_get_shader_color" -nodeType "user_ibl_env" -nodeType "user_ibl_rect"
		 -nodeType "mia_material_x_passes" -nodeType "mi_metallic_paint_x_passes" -nodeType "mi_car_paint_phen_x_passes"
		 -nodeType "misss_fast_shader_x_passes" -dataType "byteArray" "Mayatomr" "2014.0 - 3.11.1.4 ";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2014";
fileInfo "version" "2014 x64";
fileInfo "cutIdentifier" "201303010241-864206";
fileInfo "osv" "Microsoft Windows 8 Business Edition, 64-bit  (Build 9200)\n";
fileInfo "license" "student";
createNode transform -s -n "persp";
	setAttr ".v" no;
	setAttr ".t" -type "double3" -12.425697172226883 16.002992506174369 -8.0986667124759997 ;
	setAttr ".r" -type "double3" -38.138352738160961 -1197.0000000003781 0 ;
createNode camera -s -n "perspShape" -p "persp";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".coi" 12.157290224216421;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".hc" -type "string" "viewSet -p %camera";
createNode transform -s -n "top";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 100.1 0 ;
	setAttr ".r" -type "double3" -89.999999999999986 0 0 ;
createNode camera -s -n "topShape" -p "top";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
createNode transform -s -n "front";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 0 100.1 ;
createNode camera -s -n "frontShape" -p "front";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "front";
	setAttr ".den" -type "string" "front_depth";
	setAttr ".man" -type "string" "front_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".o" yes;
createNode transform -s -n "side";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 100.1 0 0 ;
	setAttr ".r" -type "double3" 0 89.999999999999986 0 ;
createNode camera -s -n "sideShape" -p "side";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
createNode transform -n "wall";
createNode mesh -n "wallShape" -p "wall";
	setAttr -k off ".v";
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:23]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 96 ".uvst[0].uvsp[0:95]" -type "float2" 0.0019499999 0.0019499999
		 0.19726001 0.0019499999 0.19726001 0.19726001 0.0019499999 0.19726001 0.20117 0.0019499999
		 0.39647999 0.0019499999 0.39647999 0.19726001 0.20117 0.19726001 0.40039 0.0019499999
		 0.59570003 0.0019499999 0.59570003 0.19726001 0.40039 0.19726001 0.59960002 0.0019499999
		 0.79492003 0.0019499999 0.79492003 0.19726001 0.59960002 0.19726001 0.79882002 0.0019499999
		 0.99414003 0.0019499999 0.99414003 0.19726001 0.79882002 0.19726001 0.0019499999
		 0.20117 0.19726001 0.20117 0.19726001 0.39647999 0.0019499999 0.39647999 0.20117
		 0.20117 0.39647999 0.20117 0.39647999 0.39647999 0.20117 0.39647999 0.40039 0.20117
		 0.59570003 0.20117 0.59570003 0.39647999 0.40039 0.39647999 0.59960002 0.20117 0.79492003
		 0.20117 0.79492003 0.39647999 0.59960002 0.39647999 0.79882002 0.20117 0.99414003
		 0.20117 0.99414003 0.39647999 0.79882002 0.39647999 0.0019499999 0.40039 0.19726001
		 0.40039 0.19726001 0.59570003 0.0019499999 0.59570003 0.20117 0.40039 0.39647999
		 0.40039 0.39647999 0.59570003 0.20117 0.59570003 0.40039 0.40039 0.59570003 0.40039
		 0.59570003 0.59570003 0.40039 0.59570003 0.59960002 0.40039 0.79492003 0.40039 0.79492003
		 0.59570003 0.59960002 0.59570003 0.79882002 0.40039 0.99414003 0.40039 0.99414003
		 0.59570003 0.79882002 0.59570003 0.0019499999 0.59960002 0.19726001 0.59960002 0.19726001
		 0.79492003 0.0019499999 0.79492003 0.20117 0.59960002 0.39647999 0.59960002 0.39647999
		 0.79492003 0.20117 0.79492003 0.40039 0.59960002 0.59570003 0.59960002 0.59570003
		 0.79492003 0.40039 0.79492003 0.59960002 0.59960002 0.79492003 0.59960002 0.79492003
		 0.79492003 0.59960002 0.79492003 0.79882002 0.59960002 0.99414003 0.59960002 0.99414003
		 0.79492003 0.79882002 0.79492003 0.0019499999 0.79882002 0.19726001 0.79882002 0.19726001
		 0.99414003 0.0019499999 0.99414003 0.20117 0.79882002 0.39647999 0.79882002 0.39647999
		 0.99414003 0.20117 0.99414003 0.40039 0.79882002 0.59570003 0.79882002 0.59570003
		 0.99414003 0.40039 0.99414003 0.59960002 0.79882002 0.79492003 0.79882002 0.79492003
		 0.99414003 0.59960002 0.99414003;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 44 ".vt[0:43]"  -0.81283194 1.67657089 4.44856024 0.73993498 1.67657089 4.44856024
		 -1.13065898 7.32734823 4.43763351 1.038782954 7.32734823 4.43763351 -1.13065898 7.32734823 -4.34295321
		 1.038782954 7.32734823 -4.34295321 -0.81283194 1.67657089 -4.33202648 0.73993498 1.67657089 -4.33202648
		 -0.82062101 6.60922766 4.43902683 0.73214602 6.60922766 4.43902683 -0.82062101 6.60922766 -4.34155989
		 0.73214602 6.60922766 -4.34155989 -0.82418007 1.47750497 -4.30950212 0.75126427 1.47750497 -4.30950212
		 0.74467194 1.47748709 4.42603588 -0.81756902 1.47748709 4.42603588 -0.81377727 -0.046155758 -4.30950117
		 0.74859971 -0.046155758 -4.30950117 0.75845772 -0.04613376 4.42603827 -0.8236649 -0.04613376 4.42603827
		 0.88265693 1.67936027 4.44856024 0.88265693 1.67936027 -4.33202648 0.88739401 1.48027587 4.42603588
		 0.88948184 1.48028171 -4.30950165 -0.930067 1.67936027 -4.33202648 -0.930067 1.67936027 4.44856024
		 -0.93766099 1.48028374 -4.30950165 -0.93480504 1.48027587 4.42603588 1.35481286 7.19240189 -4.34295321
		 1.35481286 7.19240189 4.43763351 -1.44614601 7.19114113 4.43763351 -1.44614601 7.19114113 -4.34295321
		 0.662826 7.67051935 -4.34295321 0.662826 7.67051935 4.43763351 -0.75607604 7.67202044 4.43763351
		 -0.75607604 7.67202044 -4.34295321 0.27700001 8.045331001 -4.34295321 0.27700001 8.045331001 4.43763351
		 -0.37175104 8.048370361 4.43763351 -0.37175104 8.048370361 -4.34295321 -0.051641989 8.43265724 -4.34295321
		 -0.051641989 8.43265724 4.43763351 -0.044659998 8.43700695 4.43763351 -0.044659998 8.43700695 -4.34295321;
	setAttr -s 66 ".ed[0:65]"  1 7 0 7 11 0 11 9 0 9 1 0 6 0 0 0 8 0 8 10 0
		 10 6 0 11 5 0 5 3 0 3 9 0 8 2 0 2 4 0 4 10 0 21 20 0 20 22 0 22 23 0 23 21 0 25 24 0
		 24 26 0 26 27 0 27 25 0 13 14 0 14 18 0 18 17 0 17 13 0 15 12 0 12 16 0 16 19 0 19 15 0
		 1 20 0 21 7 0 1 14 0 14 22 0 13 23 0 13 7 0 6 24 0 25 0 0 6 12 0 12 26 0 15 27 0
		 15 0 0 5 28 0 28 29 0 29 3 0 2 30 0 30 31 0 31 4 0 28 32 0 32 33 0 33 29 0 30 34 0
		 34 35 0 35 31 0 32 36 0 36 37 0 37 33 0 34 38 0 38 39 0 39 35 0 36 40 0 40 41 0 41 37 0
		 38 42 0 42 43 0 43 39 0;
	setAttr -s 24 -ch 96 ".fc[0:23]" -type "polyFaces" 
		f 4 0 1 2 3
		mu 0 4 0 1 2 3
		f 4 4 5 6 7
		mu 0 4 4 5 6 7
		f 4 -3 8 9 10
		mu 0 4 8 9 10 11
		f 4 -7 11 12 13
		mu 0 4 12 13 14 15
		f 4 14 15 16 17
		mu 0 4 16 17 18 19
		f 4 18 19 20 21
		mu 0 4 20 21 22 23
		f 4 22 23 24 25
		mu 0 4 24 25 26 27
		f 4 26 27 28 29
		mu 0 4 28 29 30 31
		f 4 -1 30 -15 31
		mu 0 4 32 33 34 35
		f 4 32 33 -16 -31
		mu 0 4 36 37 38 39
		f 4 -23 34 -17 -34
		mu 0 4 40 41 42 43
		f 4 35 -32 -18 -35
		mu 0 4 44 45 46 47
		f 4 -5 36 -19 37
		mu 0 4 48 49 50 51
		f 4 38 39 -20 -37
		mu 0 4 52 53 54 55
		f 4 -27 40 -21 -40
		mu 0 4 56 57 58 59
		f 4 41 -38 -22 -41
		mu 0 4 60 61 62 63
		f 4 -10 42 43 44
		mu 0 4 64 65 66 67
		f 4 -13 45 46 47
		mu 0 4 68 69 70 71
		f 4 -44 48 49 50
		mu 0 4 72 73 74 75
		f 4 -47 51 52 53
		mu 0 4 76 77 78 79
		f 4 -50 54 55 56
		mu 0 4 80 81 82 83
		f 4 -53 57 58 59
		mu 0 4 84 85 86 87
		f 4 -56 60 61 62
		mu 0 4 88 89 90 91
		f 4 -59 63 64 65
		mu 0 4 92 93 94 95;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode lightLinker -s -n "lightLinker1";
	setAttr -s 50 ".lnk";
	setAttr -s 50 ".slnk";
createNode displayLayerManager -n "layerManager";
createNode displayLayer -n "defaultLayer";
createNode renderLayerManager -n "renderLayerManager";
createNode renderLayer -n "defaultRenderLayer";
	setAttr ".g" yes;
createNode phong -n "lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo1";
createNode file -n "lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "place2dTexture1";
createNode bump2d -n "bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "place2dTexture2";
createNode file -n "ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "place2dTexture3";
createNode script -n "uiConfigurationScriptNode";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"top\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n"
		+ "                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -objectFilterShowInHUD 1\n                -isFiltered 0\n"
		+ "                -colorResolution 4 4 \n                -bumpResolution 4 4 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n"
		+ "                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"top\" \n"
		+ "            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -objectFilterShowInHUD 1\n            -isFiltered 0\n"
		+ "            -colorResolution 4 4 \n            -bumpResolution 4 4 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 0\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n"
		+ "            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"side\" \n"
		+ "                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n"
		+ "                -maxConstantTransparency 1\n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 4 4 \n                -bumpResolution 4 4 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n"
		+ "                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n"
		+ "            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 4 4 \n            -bumpResolution 4 4 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 0\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n"
		+ "            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n"
		+ "                -camera \"front\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n"
		+ "                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 4 4 \n                -bumpResolution 4 4 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n"
		+ "                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n"
		+ "\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n"
		+ "            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 4 4 \n            -bumpResolution 4 4 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 0\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n"
		+ "            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n"
		+ "\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 1\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n"
		+ "                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n"
		+ "                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n"
		+ "                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 1\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n"
		+ "            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n"
		+ "            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n"
		+ "            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `outlinerPanel -unParent -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            outlinerEditor -e \n                -showShapes 0\n                -showReferenceNodes 1\n                -showReferenceMembers 1\n                -showAttributes 0\n                -showConnected 0\n                -showAnimCurvesOnly 0\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 1\n                -showAssets 1\n                -showContainedOnly 1\n                -showPublishedAsConnected 0\n                -showContainerContents 1\n"
		+ "                -ignoreDagHierarchy 0\n                -expandConnections 0\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 0\n                -highlightActive 1\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"defaultSetFilter\" \n                -showSetMembers 1\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n"
		+ "                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showReferenceNodes 1\n            -showReferenceMembers 1\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n"
		+ "            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            $editorName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\tif ($useSceneConfig) {\n\t\toutlinerPanel -e -to $panelName;\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"graphEditor\" -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n"
		+ "                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n"
		+ "                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                -mapMotionTrails 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showResults \"off\" \n                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -stackedCurves 0\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -displayNormalized 0\n"
		+ "                -preSelectionHighlight 0\n                -constrainDrag 0\n                -classicMode 1\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n"
		+ "                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n"
		+ "                -showPinIcons 1\n                -mapMotionTrails 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showResults \"off\" \n                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -stackedCurves 0\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -displayNormalized 0\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -classicMode 1\n                $editorName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dopeSheetPanel\" (localizedPanelLabel(\"Dope Sheet\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dopeSheetPanel\" -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n"
		+ "                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n"
		+ "                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n"
		+ "                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n"
		+ "                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n"
		+ "                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"clipEditorPanel\" (localizedPanelLabel(\"Trax Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"clipEditorPanel\" -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n"
		+ "                -manageSequencer 0 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -manageSequencer 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"sequenceEditorPanel\" (localizedPanelLabel(\"Camera Sequencer\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"sequenceEditorPanel\" -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -manageSequencer 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -manageSequencer 1 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n"
		+ "\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph Hierarchy\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"hyperGraphPanel\" -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showConnectionFromSelected 0\n                -showConnectionToSelected 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n"
		+ "                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n"
		+ "                -showConnectionFromSelected 0\n                -showConnectionToSelected 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperShadePanel\" (localizedPanelLabel(\"Hypershade\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"hyperShadePanel\" -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"visorPanel\" (localizedPanelLabel(\"Visor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"visorPanel\" -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"nodeEditorPanel\" (localizedPanelLabel(\"Node Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"nodeEditorPanel\" -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n"
		+ "            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -defaultPinnedState 0\n                -ignoreAssets 1\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -keyReleaseCommand \"nodeEdKeyReleaseCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -island 0\n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -syncedSelection 1\n                -extendToShapes 1\n                $editorName;\n\t\t\tif (`objExists nodeEditorPanel1Info`) nodeEditor -e -restoreInfo nodeEditorPanel1Info $editorName;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -defaultPinnedState 0\n                -ignoreAssets 1\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -keyReleaseCommand \"nodeEdKeyReleaseCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -island 0\n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n"
		+ "                -syncedSelection 1\n                -extendToShapes 1\n                $editorName;\n\t\t\tif (`objExists nodeEditorPanel1Info`) nodeEditor -e -restoreInfo nodeEditorPanel1Info $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"createNodePanel\" (localizedPanelLabel(\"Create Node\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"createNodePanel\" -l (localizedPanelLabel(\"Create Node\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Create Node\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"polyTexturePlacementPanel\" (localizedPanelLabel(\"UV Texture Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"polyTexturePlacementPanel\" -l (localizedPanelLabel(\"UV Texture Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"UV Texture Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"renderWindowPanel\" (localizedPanelLabel(\"Render View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"renderWindowPanel\" -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"blendShapePanel\" (localizedPanelLabel(\"Blend Shape\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\tblendShapePanel -unParent -l (localizedPanelLabel(\"Blend Shape\")) -mbv $menusOkayInPanels ;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n"
		+ "\t\tblendShapePanel -edit -l (localizedPanelLabel(\"Blend Shape\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynRelEdPanel\" (localizedPanelLabel(\"Dynamic Relationships\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dynRelEdPanel\" -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"relationshipPanel\" (localizedPanelLabel(\"Relationship Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"relationshipPanel\" -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"referenceEditorPanel\" (localizedPanelLabel(\"Reference Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"referenceEditorPanel\" -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"componentEditorPanel\" (localizedPanelLabel(\"Component Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"componentEditorPanel\" -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\tif ($useSceneConfig) {\n\t\tscriptedPanel -e -to $panelName;\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynPaintScriptedPanelType\" (localizedPanelLabel(\"Paint Effects\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dynPaintScriptedPanelType\" -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"scriptEditorPanel\" (localizedPanelLabel(\"Script Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"scriptEditorPanel\" -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n\t\t\t\t-defaultImage \"\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"single\\\" -ps 1 100 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Persp View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        setFocus `paneLayout -q -p1 $gMainPane`;\n        sceneUIReplacement -deleteRemaining;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 12 -divisions 5 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 24 -ast 1 -aet 48 ";
	setAttr ".st" 6;
createNode lambert -n "lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo2";
createNode file -n "file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "place2dTexture4";
createNode file -n "file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "place2dTexture5";
createNode bump2d -n "bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode mentalrayItemsList -s -n "mentalrayItemsList";
createNode mentalrayGlobals -s -n "mentalrayGlobals";
	setAttr ".rvb" 3;
	setAttr ".ivb" no;
createNode mentalrayOptions -s -n "miDefaultOptions";
	addAttr -ci true -m -sn "stringOptions" -ln "stringOptions" -at "compound" -nc 
		3;
	addAttr -ci true -sn "name" -ln "name" -dt "string" -p "stringOptions";
	addAttr -ci true -sn "value" -ln "value" -dt "string" -p "stringOptions";
	addAttr -ci true -sn "type" -ln "type" -dt "string" -p "stringOptions";
	setAttr -s 48 ".stringOptions";
	setAttr ".stringOptions[0].name" -type "string" "rast motion factor";
	setAttr ".stringOptions[0].value" -type "string" "1.0";
	setAttr ".stringOptions[0].type" -type "string" "scalar";
	setAttr ".stringOptions[1].name" -type "string" "rast transparency depth";
	setAttr ".stringOptions[1].value" -type "string" "8";
	setAttr ".stringOptions[1].type" -type "string" "integer";
	setAttr ".stringOptions[2].name" -type "string" "rast useopacity";
	setAttr ".stringOptions[2].value" -type "string" "true";
	setAttr ".stringOptions[2].type" -type "string" "boolean";
	setAttr ".stringOptions[3].name" -type "string" "importon";
	setAttr ".stringOptions[3].value" -type "string" "false";
	setAttr ".stringOptions[3].type" -type "string" "boolean";
	setAttr ".stringOptions[4].name" -type "string" "importon density";
	setAttr ".stringOptions[4].value" -type "string" "1.0";
	setAttr ".stringOptions[4].type" -type "string" "scalar";
	setAttr ".stringOptions[5].name" -type "string" "importon merge";
	setAttr ".stringOptions[5].value" -type "string" "0.0";
	setAttr ".stringOptions[5].type" -type "string" "scalar";
	setAttr ".stringOptions[6].name" -type "string" "importon trace depth";
	setAttr ".stringOptions[6].value" -type "string" "0";
	setAttr ".stringOptions[6].type" -type "string" "integer";
	setAttr ".stringOptions[7].name" -type "string" "importon traverse";
	setAttr ".stringOptions[7].value" -type "string" "true";
	setAttr ".stringOptions[7].type" -type "string" "boolean";
	setAttr ".stringOptions[8].name" -type "string" "shadowmap pixel samples";
	setAttr ".stringOptions[8].value" -type "string" "3";
	setAttr ".stringOptions[8].type" -type "string" "integer";
	setAttr ".stringOptions[9].name" -type "string" "ambient occlusion";
	setAttr ".stringOptions[9].value" -type "string" "false";
	setAttr ".stringOptions[9].type" -type "string" "boolean";
	setAttr ".stringOptions[10].name" -type "string" "ambient occlusion rays";
	setAttr ".stringOptions[10].value" -type "string" "256";
	setAttr ".stringOptions[10].type" -type "string" "integer";
	setAttr ".stringOptions[11].name" -type "string" "ambient occlusion cache";
	setAttr ".stringOptions[11].value" -type "string" "false";
	setAttr ".stringOptions[11].type" -type "string" "boolean";
	setAttr ".stringOptions[12].name" -type "string" "ambient occlusion cache density";
	setAttr ".stringOptions[12].value" -type "string" "1.0";
	setAttr ".stringOptions[12].type" -type "string" "scalar";
	setAttr ".stringOptions[13].name" -type "string" "ambient occlusion cache points";
	setAttr ".stringOptions[13].value" -type "string" "64";
	setAttr ".stringOptions[13].type" -type "string" "integer";
	setAttr ".stringOptions[14].name" -type "string" "irradiance particles";
	setAttr ".stringOptions[14].value" -type "string" "false";
	setAttr ".stringOptions[14].type" -type "string" "boolean";
	setAttr ".stringOptions[15].name" -type "string" "irradiance particles rays";
	setAttr ".stringOptions[15].value" -type "string" "256";
	setAttr ".stringOptions[15].type" -type "string" "integer";
	setAttr ".stringOptions[16].name" -type "string" "irradiance particles interpolate";
	setAttr ".stringOptions[16].value" -type "string" "1";
	setAttr ".stringOptions[16].type" -type "string" "integer";
	setAttr ".stringOptions[17].name" -type "string" "irradiance particles interppoints";
	setAttr ".stringOptions[17].value" -type "string" "64";
	setAttr ".stringOptions[17].type" -type "string" "integer";
	setAttr ".stringOptions[18].name" -type "string" "irradiance particles indirect passes";
	setAttr ".stringOptions[18].value" -type "string" "0";
	setAttr ".stringOptions[18].type" -type "string" "integer";
	setAttr ".stringOptions[19].name" -type "string" "irradiance particles scale";
	setAttr ".stringOptions[19].value" -type "string" "1.0";
	setAttr ".stringOptions[19].type" -type "string" "scalar";
	setAttr ".stringOptions[20].name" -type "string" "irradiance particles env";
	setAttr ".stringOptions[20].value" -type "string" "true";
	setAttr ".stringOptions[20].type" -type "string" "boolean";
	setAttr ".stringOptions[21].name" -type "string" "irradiance particles env rays";
	setAttr ".stringOptions[21].value" -type "string" "256";
	setAttr ".stringOptions[21].type" -type "string" "integer";
	setAttr ".stringOptions[22].name" -type "string" "irradiance particles env scale";
	setAttr ".stringOptions[22].value" -type "string" "1";
	setAttr ".stringOptions[22].type" -type "string" "integer";
	setAttr ".stringOptions[23].name" -type "string" "irradiance particles rebuild";
	setAttr ".stringOptions[23].value" -type "string" "true";
	setAttr ".stringOptions[23].type" -type "string" "boolean";
	setAttr ".stringOptions[24].name" -type "string" "irradiance particles file";
	setAttr ".stringOptions[24].value" -type "string" "";
	setAttr ".stringOptions[24].type" -type "string" "string";
	setAttr ".stringOptions[25].name" -type "string" "geom displace motion factor";
	setAttr ".stringOptions[25].value" -type "string" "1.0";
	setAttr ".stringOptions[25].type" -type "string" "scalar";
	setAttr ".stringOptions[26].name" -type "string" "contrast all buffers";
	setAttr ".stringOptions[26].value" -type "string" "true";
	setAttr ".stringOptions[26].type" -type "string" "boolean";
	setAttr ".stringOptions[27].name" -type "string" "finalgather normal tolerance";
	setAttr ".stringOptions[27].value" -type "string" "25.842";
	setAttr ".stringOptions[27].type" -type "string" "scalar";
	setAttr ".stringOptions[28].name" -type "string" "trace camera clip";
	setAttr ".stringOptions[28].value" -type "string" "false";
	setAttr ".stringOptions[28].type" -type "string" "boolean";
	setAttr ".stringOptions[29].name" -type "string" "unified sampling";
	setAttr ".stringOptions[29].value" -type "string" "true";
	setAttr ".stringOptions[29].type" -type "string" "boolean";
	setAttr ".stringOptions[30].name" -type "string" "samples quality";
	setAttr ".stringOptions[30].value" -type "string" "0.25 0.25 0.25 0.25";
	setAttr ".stringOptions[30].type" -type "string" "color";
	setAttr ".stringOptions[31].name" -type "string" "samples min";
	setAttr ".stringOptions[31].value" -type "string" "1.0";
	setAttr ".stringOptions[31].type" -type "string" "scalar";
	setAttr ".stringOptions[32].name" -type "string" "samples max";
	setAttr ".stringOptions[32].value" -type "string" "100.0";
	setAttr ".stringOptions[32].type" -type "string" "scalar";
	setAttr ".stringOptions[33].name" -type "string" "samples error cutoff";
	setAttr ".stringOptions[33].value" -type "string" "0.0 0.0 0.0 0.0";
	setAttr ".stringOptions[33].type" -type "string" "color";
	setAttr ".stringOptions[34].name" -type "string" "samples per object";
	setAttr ".stringOptions[34].value" -type "string" "false";
	setAttr ".stringOptions[34].type" -type "string" "boolean";
	setAttr ".stringOptions[35].name" -type "string" "progressive";
	setAttr ".stringOptions[35].value" -type "string" "false";
	setAttr ".stringOptions[35].type" -type "string" "boolean";
	setAttr ".stringOptions[36].name" -type "string" "progressive max time";
	setAttr ".stringOptions[36].value" -type "string" "0";
	setAttr ".stringOptions[36].type" -type "string" "integer";
	setAttr ".stringOptions[37].name" -type "string" "progressive subsampling size";
	setAttr ".stringOptions[37].value" -type "string" "1";
	setAttr ".stringOptions[37].type" -type "string" "integer";
	setAttr ".stringOptions[38].name" -type "string" "iray";
	setAttr ".stringOptions[38].value" -type "string" "false";
	setAttr ".stringOptions[38].type" -type "string" "boolean";
	setAttr ".stringOptions[39].name" -type "string" "light relative scale";
	setAttr ".stringOptions[39].value" -type "string" "0.31831";
	setAttr ".stringOptions[39].type" -type "string" "scalar";
	setAttr ".stringOptions[40].name" -type "string" "trace camera motion vectors";
	setAttr ".stringOptions[40].value" -type "string" "false";
	setAttr ".stringOptions[40].type" -type "string" "boolean";
	setAttr ".stringOptions[41].name" -type "string" "ray differentials";
	setAttr ".stringOptions[41].value" -type "string" "true";
	setAttr ".stringOptions[41].type" -type "string" "boolean";
	setAttr ".stringOptions[42].name" -type "string" "environment lighting mode";
	setAttr ".stringOptions[42].value" -type "string" "off";
	setAttr ".stringOptions[42].type" -type "string" "string";
	setAttr ".stringOptions[43].name" -type "string" "environment lighting quality";
	setAttr ".stringOptions[43].value" -type "string" "0.167";
	setAttr ".stringOptions[43].type" -type "string" "scalar";
	setAttr ".stringOptions[44].name" -type "string" "environment lighting shadow";
	setAttr ".stringOptions[44].value" -type "string" "transparent";
	setAttr ".stringOptions[44].type" -type "string" "string";
	setAttr ".stringOptions[45].name" -type "string" "environment lighting resolution";
	setAttr ".stringOptions[45].value" -type "string" "512";
	setAttr ".stringOptions[45].type" -type "string" "integer";
	setAttr ".stringOptions[46].name" -type "string" "environment lighting shader samples";
	setAttr ".stringOptions[46].value" -type "string" "2";
	setAttr ".stringOptions[46].type" -type "string" "integer";
	setAttr ".stringOptions[47].name" -type "string" "environment lighting scale";
	setAttr ".stringOptions[47].value" -type "string" "1.0 1.0 1.0";
	setAttr ".stringOptions[47].type" -type "string" "color";
createNode mentalrayFramebuffer -s -n "miDefaultFramebuffer";
createNode phong -n "Mur5_optimized2014_2_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "Mur5_optimized2014_2_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_2_materialInfo1";
createNode file -n "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_2_place2dTexture1";
createNode bump2d -n "Mur5_optimized2014_2_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_2_place2dTexture2";
createNode file -n "Mur5_optimized2014_2_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "Mur5_optimized2014_2_place2dTexture3";
createNode lambert -n "Mur5_optimized2014_2_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "Mur5_optimized2014_2_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_2_materialInfo2";
createNode file -n "Mur5_optimized2014_2_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "Mur5_optimized2014_2_place2dTexture4";
createNode file -n "Mur5_optimized2014_2_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "Mur5_optimized2014_2_place2dTexture5";
createNode bump2d -n "Mur5_optimized2014_2_bump2d2";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "Mur5_optimized2014_4_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "Mur5_optimized2014_4_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_4_materialInfo1";
createNode file -n "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_4_place2dTexture1";
createNode bump2d -n "Mur5_optimized2014_4_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_4_place2dTexture2";
createNode file -n "Mur5_optimized2014_4_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "Mur5_optimized2014_4_place2dTexture3";
createNode lambert -n "Mur5_optimized2014_4_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "Mur5_optimized2014_4_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_4_materialInfo2";
createNode file -n "Mur5_optimized2014_4_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "Mur5_optimized2014_4_place2dTexture4";
createNode file -n "Mur5_optimized2014_4_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "Mur5_optimized2014_4_place2dTexture5";
createNode bump2d -n "Mur5_optimized2014_4_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "lambert10";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "wallSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo3";
createNode file -n "lambert9_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "place2dTexture6";
createNode bump2d -n "bump2d3";
createNode file -n "lambert9_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "place2dTexture7";
createNode file -n "lambert9_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "place2dTexture8";
createNode phong -n "lambert11";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "wallSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo4";
createNode bump2d -n "bump2d4";
	setAttr ".vc1" -type "float3" 0 4.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "lambert11_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "place2dTexture9";
createNode file -n "lambert11_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "place2dTexture10";
createNode file -n "lambert11_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "place2dTexture11";
createNode phong -n "lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "wallSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo5";
createNode file -n "lambert12_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush1Text.png";
createNode place2dTexture -n "place2dTexture12";
createNode bump2d -n "bump2d5";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "lambert12_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush1Norm.png";
createNode place2dTexture -n "place2dTexture13";
createNode file -n "lambert12_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "place2dTexture14";
createNode phong -n "murPort4_2014_tri:lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:wallBlockSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:materialInfo1";
createNode file -n "murPort4_2014_tri:lambert12_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture1";
createNode bump2d -n "murPort4_2014_tri:bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture2";
createNode file -n "murPort4_2014_tri:ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture3";
createNode phong -n "murPort4_2014_tri:lambert13";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:wallBlockSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:materialInfo2";
createNode file -n "murPort4_2014_tri:lambert13_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture4";
createNode bump2d -n "murPort4_2014_tri:bump2d2";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture5";
createNode phong -n "murPort4_2014_tri:lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:mur22227_materialInfo1";
createNode file -n "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture1";
createNode bump2d -n "murPort4_2014_tri:mur22227_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture2";
createNode file -n "murPort4_2014_tri:mur22227_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture3";
createNode lambert -n "murPort4_2014_tri:lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murPort4_2014_tri:lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:mur22227_materialInfo2";
createNode file -n "murPort4_2014_tri:file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture4";
createNode file -n "murPort4_2014_tri:file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture5";
createNode bump2d -n "murPort4_2014_tri:mur22227_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murPort4_2014_tri:Mur5_optimized2014_2_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:Mur5_optimized2014_2_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:Mur5_optimized2014_2_materialInfo1";
createNode file -n "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1";
createNode bump2d -n "murPort4_2014_tri:Mur5_optimized2014_2_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2";
createNode file -n "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3";
createNode lambert -n "murPort4_2014_tri:Mur5_optimized2014_2_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murPort4_2014_tri:Mur5_optimized2014_2_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:Mur5_optimized2014_2_materialInfo2";
createNode file -n "murPort4_2014_tri:Mur5_optimized2014_2_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4";
createNode file -n "murPort4_2014_tri:Mur5_optimized2014_2_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5";
createNode bump2d -n "murPort4_2014_tri:Mur5_optimized2014_2_bump2d2";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murPort4_2014_tri:Mur5_optimized2014_4_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:Mur5_optimized2014_4_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:Mur5_optimized2014_4_materialInfo1";
createNode file -n "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1";
createNode bump2d -n "murPort4_2014_tri:Mur5_optimized2014_4_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2";
createNode file -n "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3";
createNode lambert -n "murPort4_2014_tri:Mur5_optimized2014_4_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murPort4_2014_tri:Mur5_optimized2014_4_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:Mur5_optimized2014_4_materialInfo2";
createNode file -n "murPort4_2014_tri:Mur5_optimized2014_4_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4";
createNode file -n "murPort4_2014_tri:Mur5_optimized2014_4_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5";
createNode bump2d -n "murPort4_2014_tri:Mur5_optimized2014_4_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murPort4_2014_tri:lambert10";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:wallSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:materialInfo3";
createNode file -n "murPort4_2014_tri:lambert9_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture6";
createNode bump2d -n "murPort4_2014_tri:bump2d3";
createNode file -n "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture7";
createNode file -n "murPort4_2014_tri:lambert9_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture8";
createNode phong -n "murPort4_2014_tri:lambert11";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:wallSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:materialInfo4";
createNode bump2d -n "murPort4_2014_tri:bump2d4";
	setAttr ".vc1" -type "float3" 0 4.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:lambert11_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture9";
createNode file -n "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture10";
createNode file -n "murPort4_2014_tri:lambert11_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture11";
createNode phong -n "murPort4_2014_tri:mur22227_lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:wallSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:materialInfo5";
createNode file -n "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture12";
createNode bump2d -n "murPort4_2014_tri:bump2d5";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture13";
createNode file -n "murPort4_2014_tri:lambert12_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture14";
createNode phong -n "murPort4_2014_tri:lambert16";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:wallBlockSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:materialInfo6";
createNode file -n "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture15";
createNode bump2d -n "murPort4_2014_tri:bump2d6";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 1.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture16";
createNode phong -n "murPort4_2014_tri:lambert17";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:wallBlockSG3";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:materialInfo7";
createNode file -n "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture17";
createNode bump2d -n "murPort4_2014_tri:bump2d7";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 1.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal_u1_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture18";
createNode phong -n "murPort4_2014_tri:murBlock6_2014_lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:murBlock6_2014_wallBlockSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murBlock6_2014_materialInfo1";
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture1";
createNode bump2d -n "murPort4_2014_tri:murBlock6_2014_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture2";
createNode file -n "murPort4_2014_tri:murBlock6_2014_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture3";
createNode phong -n "murPort4_2014_tri:murBlock6_2014_lambert13";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:murBlock6_2014_wallBlockSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murBlock6_2014_materialInfo2";
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture4";
createNode bump2d -n "murPort4_2014_tri:murBlock6_2014_bump2d2";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture5";
createNode phong -n "murPort4_2014_tri:murBlock6_2014_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:murBlock6_2014_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo1";
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1";
createNode bump2d -n "murPort4_2014_tri:murBlock6_2014_mur22227_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2";
createNode file -n "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3";
createNode lambert -n "murPort4_2014_tri:murBlock6_2014_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murPort4_2014_tri:murBlock6_2014_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo2";
createNode file -n "murPort4_2014_tri:murBlock6_2014_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4";
createNode file -n "murPort4_2014_tri:murBlock6_2014_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5";
createNode bump2d -n "murPort4_2014_tri:murBlock6_2014_mur22227_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo1";
createNode file -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1";
createNode bump2d -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2";
createNode file -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3";
createNode lambert -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo2";
createNode file -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4";
createNode file -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5";
createNode bump2d -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d2";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo1";
createNode file -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1";
createNode bump2d -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2";
createNode file -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3";
createNode lambert -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo2";
createNode file -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4";
createNode file -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5";
createNode bump2d -n "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murPort4_2014_tri:murBlock6_2014_lambert10";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:murBlock6_2014_wallSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murBlock6_2014_materialInfo3";
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture6";
createNode bump2d -n "murPort4_2014_tri:murBlock6_2014_bump2d3";
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture7";
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture8";
createNode phong -n "murPort4_2014_tri:murBlock6_2014_lambert11";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:murBlock6_2014_wallSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murBlock6_2014_materialInfo4";
createNode bump2d -n "murPort4_2014_tri:murBlock6_2014_bump2d4";
	setAttr ".vc1" -type "float3" 0 4.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture9";
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture10";
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture11";
createNode phong -n "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:murBlock6_2014_wallSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murBlock6_2014_materialInfo5";
createNode file -n "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture12";
createNode bump2d -n "murPort4_2014_tri:murBlock6_2014_bump2d5";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture13";
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture14";
createNode phong -n "murPort4_2014_tri:murBlock6_2014_lambert16";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:murBlock6_2014_wallBlockSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murBlock6_2014_materialInfo6";
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture15";
createNode bump2d -n "murPort4_2014_tri:murBlock6_2014_bump2d6";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 1.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture16";
createNode phong -n "murPort4_2014_tri:murBlock6_2014_lambert17";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:murBlock6_2014_wallBlockSG3";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murBlock6_2014_materialInfo7";
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture17";
createNode bump2d -n "murPort4_2014_tri:murBlock6_2014_bump2d7";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 1.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal_u1_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:murBlock6_2014_place2dTexture18";
createNode phong -n "murPort4_2014_tri:mur22227_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:mur22227_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:mur22227_materialInfo3";
createNode file -n "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture6";
createNode bump2d -n "murPort4_2014_tri:mur22227_bump2d3";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture7";
createNode file -n "murPort4_2014_tri:mur22227_ReflectionMap1";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture8";
createNode lambert -n "murPort4_2014_tri:mur22227_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murPort4_2014_tri:mur22227_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:mur22227_materialInfo4";
createNode file -n "murPort4_2014_tri:mur22227_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture9";
createNode file -n "murPort4_2014_tri:mur22227_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture10";
createNode bump2d -n "murPort4_2014_tri:mur22227_bump2d4";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo1";
createNode file -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1";
createNode bump2d -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2";
createNode file -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3";
createNode lambert -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo2";
createNode file -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4";
createNode file -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5";
createNode bump2d -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d2";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo1";
createNode file -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1";
createNode bump2d -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2";
createNode file -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3";
createNode lambert -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo2";
createNode file -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4";
createNode file -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5";
createNode bump2d -n "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murPort4_2014_tri:mur22227_lambert10";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:mur22227_wallSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:mur22227_materialInfo5";
createNode file -n "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture11";
createNode bump2d -n "murPort4_2014_tri:mur22227_bump2d5";
createNode file -n "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture12";
createNode file -n "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture13";
createNode phong -n "murPort4_2014_tri:mur22227_lambert11";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:mur22227_wallSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:mur22227_materialInfo6";
createNode bump2d -n "murPort4_2014_tri:mur22227_bump2d6";
	setAttr ".vc1" -type "float3" 0 4.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture14";
createNode file -n "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture15";
createNode file -n "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture16";
createNode phong -n "murPort4_2014_tri:mur22227_lambert13";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:mur22227_wallSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:mur22227_materialInfo7";
createNode file -n "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture17";
createNode bump2d -n "murPort4_2014_tri:mur22227_bump2d7";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture18";
createNode file -n "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murPort4_2014_tri:mur22227_place2dTexture19";
createNode shadingEngine -n "murPort4_2014_tri:murPort2:defaultMat";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:murPort2:materialInfo1";
createNode lambert -n "murPort4_2014_tri:murPort2:defaultMat1";
	setAttr ".ambc" -type "float3" 0.40000001 0.40000001 0.40000001 ;
createNode file -n "murPort4_2014_tri:murPort2:defaultMat1F";
	setAttr ".ftn" -type "string" "murPort2.bmp";
createNode place2dTexture -n "murPort4_2014_tri:murPort2:defaultMat1P2D";
createNode groupId -n "murPort4_2014_tri:groupId4";
	setAttr ".ihi" 0;
createNode lambert -n "murPort4_2014_tri:lambert18";
createNode shadingEngine -n "murPort4_2014_tri:lambert18SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:materialInfo8";
createNode file -n "murPort4_2014_tri:file3";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort2_texture.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture19";
createNode file -n "murPort4_2014_tri:file4";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort2_normal.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture20";
createNode bump2d -n "murPort4_2014_tri:bump2d8";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murPort4_2014_tri:lambert19";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murPort4_2014_tri:polySurface53SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murPort4_2014_tri:materialInfo9";
createNode file -n "murPort4_2014_tri:lambert18_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort5_texture.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture21";
createNode bump2d -n "murPort4_2014_tri:bump2d9";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort4_normal.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture22";
createNode hyperGraphInfo -n "murPort4_2014_tri:nodeEditorPanel1Info";
createNode hyperView -n "murPort4_2014_tri:hyperView1";
	setAttr ".dag" no;
createNode hyperLayout -n "murPort4_2014_tri:hyperLayout1";
	setAttr ".ihi" 0;
	setAttr -s 5 ".hyp";
	setAttr ".hyp[0].nvs" 1920;
	setAttr ".hyp[1].nvs" 1920;
	setAttr ".hyp[2].nvs" 1920;
	setAttr ".hyp[3].nvs" 1920;
	setAttr ".hyp[4].nvs" 1920;
	setAttr ".anf" yes;
createNode file -n "murPort4_2014_tri:file5";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort4_normal.png";
createNode place2dTexture -n "murPort4_2014_tri:place2dTexture23";
createNode bump2d -n "murPort4_2014_tri:bump2d10";
	setAttr ".vc1" -type "float3" 0 1.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode shadingEngine -n "MurV2exportFromZbrush:defaultMat";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "MurV2exportFromZbrush:materialInfo1";
createNode groupId -n "MurV2exportFromZbrush:groupId1";
	setAttr ".ihi" 0;
createNode lambert -n "MurV2exportFromZbrush:defaultMat1";
	setAttr ".ambc" -type "float3" 0.40000001 0.40000001 0.40000001 ;
createNode file -n "MurV2exportFromZbrush:defaultMat1F";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush3Text.png";
createNode place2dTexture -n "MurV2exportFromZbrush:defaultMat1P2D";
createNode file -n "file3";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush3Norm.png";
createNode place2dTexture -n "place2dTexture15";
createNode bump2d -n "bump2d6";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode hyperGraphInfo -n "nodeEditorPanel1Info";
createNode hyperView -n "hyperView1";
	setAttr ".dag" no;
createNode hyperLayout -n "hyperLayout1";
	setAttr ".ihi" 0;
	setAttr ".anf" yes;
select -ne :time1;
	setAttr ".o" 1;
	setAttr ".unw" 1;
select -ne :renderPartition;
	setAttr -s 50 ".st";
select -ne :initialShadingGroup;
	setAttr ".ro" yes;
select -ne :initialParticleSE;
	setAttr ".ro" yes;
select -ne :defaultShaderList1;
	setAttr -s 50 ".s";
select -ne :defaultTextureList1;
	setAttr -s 122 ".tx";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderUtilityList1;
	setAttr -s 170 ".u";
select -ne :defaultRenderingList1;
select -ne :renderGlobalsList1;
select -ne :defaultResolution;
	setAttr ".pa" 1;
select -ne :hardwareRenderGlobals;
	setAttr ".ctrs" 256;
	setAttr ".btrs" 512;
select -ne :hardwareRenderingGlobals;
	setAttr ".otfna" -type "stringArray" 18 "NURBS Curves" "NURBS Surfaces" "Polygons" "Subdiv Surfaces" "Particles" "Fluids" "Image Planes" "UI:" "Lights" "Cameras" "Locators" "Joints" "IK Handles" "Deformers" "Motion Trails" "Components" "Misc. UI" "Ornaments"  ;
	setAttr ".otfva" -type "Int32Array" 18 0 1 1 1 1 1
		 1 0 0 0 0 0 0 0 0 0 0 0 ;
select -ne :defaultHardwareRenderGlobals;
	setAttr ".fn" -type "string" "im";
	setAttr ".res" -type "string" "ntsc_4d 646 485 1.333";
select -ne :ikSystem;
	setAttr -s 4 ".sol";
connectAttr "MurV2exportFromZbrush:groupId1.id" "wallShape.iog.og[0].gid";
connectAttr "MurV2exportFromZbrush:defaultMat.mwc" "wallShape.iog.og[0].gco";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:wallBlockSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:wallBlockSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:wallSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:wallSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:wallSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:wallBlockSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:wallBlockSG3.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallBlockSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallBlockSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallBlockSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallBlockSG3.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:mur22227_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:mur22227_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:mur22227_wallSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:mur22227_wallSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:mur22227_wallSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:murPort2:defaultMat.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:lambert18SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murPort4_2014_tri:polySurface53SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "MurV2exportFromZbrush:defaultMat.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:wallBlockSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:wallBlockSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:wallSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:wallSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:wallSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:wallBlockSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:wallBlockSG3.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallBlockSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallBlockSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallBlockSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murBlock6_2014_wallBlockSG3.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:mur22227_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:mur22227_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:mur22227_wallSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:mur22227_wallSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:mur22227_wallSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:murPort2:defaultMat.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:lambert18SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murPort4_2014_tri:polySurface53SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "MurV2exportFromZbrush:defaultMat.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr "lambert8_Flattened_Diffuse_u1_v1.oc" "lambert8.c";
connectAttr "bump2d1.o" "lambert8.n";
connectAttr "ReflectionMap.oc" "lambert8.rc";
connectAttr "lambert8.oc" "polySurface33SG.ss";
connectAttr "polySurface33SG.msg" "materialInfo1.sg";
connectAttr "lambert8.msg" "materialInfo1.m";
connectAttr "lambert8_Flattened_Diffuse_u1_v1.msg" "materialInfo1.t" -na;
connectAttr "place2dTexture1.o" "lambert8_Flattened_Diffuse_u1_v1.uv";
connectAttr "place2dTexture1.ofu" "lambert8_Flattened_Diffuse_u1_v1.ofu";
connectAttr "place2dTexture1.ofv" "lambert8_Flattened_Diffuse_u1_v1.ofv";
connectAttr "place2dTexture1.rf" "lambert8_Flattened_Diffuse_u1_v1.rf";
connectAttr "place2dTexture1.reu" "lambert8_Flattened_Diffuse_u1_v1.reu";
connectAttr "place2dTexture1.rev" "lambert8_Flattened_Diffuse_u1_v1.rev";
connectAttr "place2dTexture1.vt1" "lambert8_Flattened_Diffuse_u1_v1.vt1";
connectAttr "place2dTexture1.vt2" "lambert8_Flattened_Diffuse_u1_v1.vt2";
connectAttr "place2dTexture1.vt3" "lambert8_Flattened_Diffuse_u1_v1.vt3";
connectAttr "place2dTexture1.vc1" "lambert8_Flattened_Diffuse_u1_v1.vc1";
connectAttr "place2dTexture1.ofs" "lambert8_Flattened_Diffuse_u1_v1.fs";
connectAttr "lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "bump2d1.bv";
connectAttr "place2dTexture2.o" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "place2dTexture2.ofu" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "place2dTexture2.ofv" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "place2dTexture2.rf" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "place2dTexture2.reu" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "place2dTexture2.rev" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "place2dTexture2.vt1" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "place2dTexture2.vt2" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "place2dTexture2.vt3" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "place2dTexture2.vc1" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "place2dTexture2.ofs" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "place2dTexture3.o" "ReflectionMap.uv";
connectAttr "place2dTexture3.ofu" "ReflectionMap.ofu";
connectAttr "place2dTexture3.ofv" "ReflectionMap.ofv";
connectAttr "place2dTexture3.rf" "ReflectionMap.rf";
connectAttr "place2dTexture3.reu" "ReflectionMap.reu";
connectAttr "place2dTexture3.rev" "ReflectionMap.rev";
connectAttr "place2dTexture3.vt1" "ReflectionMap.vt1";
connectAttr "place2dTexture3.vt2" "ReflectionMap.vt2";
connectAttr "place2dTexture3.vt3" "ReflectionMap.vt3";
connectAttr "place2dTexture3.vc1" "ReflectionMap.vc1";
connectAttr "place2dTexture3.ofs" "ReflectionMap.fs";
connectAttr "file1.oc" "lambert9.c";
connectAttr "file1.ot" "lambert9.it";
connectAttr "bump2d2.o" "lambert9.n";
connectAttr "lambert9.oc" "lambert9SG.ss";
connectAttr "lambert9SG.msg" "materialInfo2.sg";
connectAttr "lambert9.msg" "materialInfo2.m";
connectAttr "file1.msg" "materialInfo2.t" -na;
connectAttr "place2dTexture4.c" "file1.c";
connectAttr "place2dTexture4.tf" "file1.tf";
connectAttr "place2dTexture4.rf" "file1.rf";
connectAttr "place2dTexture4.mu" "file1.mu";
connectAttr "place2dTexture4.mv" "file1.mv";
connectAttr "place2dTexture4.s" "file1.s";
connectAttr "place2dTexture4.wu" "file1.wu";
connectAttr "place2dTexture4.wv" "file1.wv";
connectAttr "place2dTexture4.re" "file1.re";
connectAttr "place2dTexture4.of" "file1.of";
connectAttr "place2dTexture4.r" "file1.ro";
connectAttr "place2dTexture4.n" "file1.n";
connectAttr "place2dTexture4.vt1" "file1.vt1";
connectAttr "place2dTexture4.vt2" "file1.vt2";
connectAttr "place2dTexture4.vt3" "file1.vt3";
connectAttr "place2dTexture4.vc1" "file1.vc1";
connectAttr "place2dTexture4.o" "file1.uv";
connectAttr "place2dTexture4.ofs" "file1.fs";
connectAttr "place2dTexture5.c" "file2.c";
connectAttr "place2dTexture5.tf" "file2.tf";
connectAttr "place2dTexture5.rf" "file2.rf";
connectAttr "place2dTexture5.mu" "file2.mu";
connectAttr "place2dTexture5.mv" "file2.mv";
connectAttr "place2dTexture5.s" "file2.s";
connectAttr "place2dTexture5.wu" "file2.wu";
connectAttr "place2dTexture5.wv" "file2.wv";
connectAttr "place2dTexture5.re" "file2.re";
connectAttr "place2dTexture5.of" "file2.of";
connectAttr "place2dTexture5.r" "file2.ro";
connectAttr "place2dTexture5.n" "file2.n";
connectAttr "place2dTexture5.vt1" "file2.vt1";
connectAttr "place2dTexture5.vt2" "file2.vt2";
connectAttr "place2dTexture5.vt3" "file2.vt3";
connectAttr "place2dTexture5.vc1" "file2.vc1";
connectAttr "place2dTexture5.o" "file2.uv";
connectAttr "place2dTexture5.ofs" "file2.fs";
connectAttr "file2.oa" "bump2d2.bv";
connectAttr ":mentalrayGlobals.msg" ":mentalrayItemsList.glb";
connectAttr ":miDefaultOptions.msg" ":mentalrayItemsList.opt" -na;
connectAttr ":miDefaultFramebuffer.msg" ":mentalrayItemsList.fb" -na;
connectAttr ":miDefaultOptions.msg" ":mentalrayGlobals.opt";
connectAttr ":miDefaultFramebuffer.msg" ":mentalrayGlobals.fb";
connectAttr "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.oc" "Mur5_optimized2014_2_lambert8.c"
		;
connectAttr "Mur5_optimized2014_2_bump2d1.o" "Mur5_optimized2014_2_lambert8.n";
connectAttr "Mur5_optimized2014_2_ReflectionMap.oc" "Mur5_optimized2014_2_lambert8.rc"
		;
connectAttr "Mur5_optimized2014_2_lambert8.oc" "Mur5_optimized2014_2_polySurface33SG.ss"
		;
connectAttr "Mur5_optimized2014_2_polySurface33SG.msg" "Mur5_optimized2014_2_materialInfo1.sg"
		;
connectAttr "Mur5_optimized2014_2_lambert8.msg" "Mur5_optimized2014_2_materialInfo1.m"
		;
connectAttr "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" "Mur5_optimized2014_2_materialInfo1.t"
		 -na;
connectAttr "Mur5_optimized2014_2_place2dTexture1.o" "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture1.ofu" "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture1.ofv" "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture1.rf" "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture1.reu" "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture1.rev" "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture1.vt1" "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture1.vt2" "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture1.vt3" "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture1.vc1" "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture1.ofs" "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "Mur5_optimized2014_2_bump2d1.bv"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture2.o" "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture2.ofu" "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture2.ofv" "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture2.rf" "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture2.reu" "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture2.rev" "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture2.vt1" "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture2.vt2" "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture2.vt3" "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture2.vc1" "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture2.ofs" "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture3.o" "Mur5_optimized2014_2_ReflectionMap.uv"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture3.ofu" "Mur5_optimized2014_2_ReflectionMap.ofu"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture3.ofv" "Mur5_optimized2014_2_ReflectionMap.ofv"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture3.rf" "Mur5_optimized2014_2_ReflectionMap.rf"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture3.reu" "Mur5_optimized2014_2_ReflectionMap.reu"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture3.rev" "Mur5_optimized2014_2_ReflectionMap.rev"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture3.vt1" "Mur5_optimized2014_2_ReflectionMap.vt1"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture3.vt2" "Mur5_optimized2014_2_ReflectionMap.vt2"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture3.vt3" "Mur5_optimized2014_2_ReflectionMap.vt3"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture3.vc1" "Mur5_optimized2014_2_ReflectionMap.vc1"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture3.ofs" "Mur5_optimized2014_2_ReflectionMap.fs"
		;
connectAttr "Mur5_optimized2014_2_file1.oc" "Mur5_optimized2014_2_lambert9.c";
connectAttr "Mur5_optimized2014_2_file1.ot" "Mur5_optimized2014_2_lambert9.it";
connectAttr "Mur5_optimized2014_2_bump2d2.o" "Mur5_optimized2014_2_lambert9.n";
connectAttr "Mur5_optimized2014_2_lambert9.oc" "Mur5_optimized2014_2_lambert9SG.ss"
		;
connectAttr "Mur5_optimized2014_2_lambert9SG.msg" "Mur5_optimized2014_2_materialInfo2.sg"
		;
connectAttr "Mur5_optimized2014_2_lambert9.msg" "Mur5_optimized2014_2_materialInfo2.m"
		;
connectAttr "Mur5_optimized2014_2_file1.msg" "Mur5_optimized2014_2_materialInfo2.t"
		 -na;
connectAttr "Mur5_optimized2014_2_place2dTexture4.c" "Mur5_optimized2014_2_file1.c"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.tf" "Mur5_optimized2014_2_file1.tf"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.rf" "Mur5_optimized2014_2_file1.rf"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.mu" "Mur5_optimized2014_2_file1.mu"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.mv" "Mur5_optimized2014_2_file1.mv"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.s" "Mur5_optimized2014_2_file1.s"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.wu" "Mur5_optimized2014_2_file1.wu"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.wv" "Mur5_optimized2014_2_file1.wv"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.re" "Mur5_optimized2014_2_file1.re"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.of" "Mur5_optimized2014_2_file1.of"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.r" "Mur5_optimized2014_2_file1.ro"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.n" "Mur5_optimized2014_2_file1.n"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.vt1" "Mur5_optimized2014_2_file1.vt1"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.vt2" "Mur5_optimized2014_2_file1.vt2"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.vt3" "Mur5_optimized2014_2_file1.vt3"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.vc1" "Mur5_optimized2014_2_file1.vc1"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.o" "Mur5_optimized2014_2_file1.uv"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture4.ofs" "Mur5_optimized2014_2_file1.fs"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.c" "Mur5_optimized2014_2_file2.c"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.tf" "Mur5_optimized2014_2_file2.tf"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.rf" "Mur5_optimized2014_2_file2.rf"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.mu" "Mur5_optimized2014_2_file2.mu"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.mv" "Mur5_optimized2014_2_file2.mv"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.s" "Mur5_optimized2014_2_file2.s"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.wu" "Mur5_optimized2014_2_file2.wu"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.wv" "Mur5_optimized2014_2_file2.wv"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.re" "Mur5_optimized2014_2_file2.re"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.of" "Mur5_optimized2014_2_file2.of"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.r" "Mur5_optimized2014_2_file2.ro"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.n" "Mur5_optimized2014_2_file2.n"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.vt1" "Mur5_optimized2014_2_file2.vt1"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.vt2" "Mur5_optimized2014_2_file2.vt2"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.vt3" "Mur5_optimized2014_2_file2.vt3"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.vc1" "Mur5_optimized2014_2_file2.vc1"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.o" "Mur5_optimized2014_2_file2.uv"
		;
connectAttr "Mur5_optimized2014_2_place2dTexture5.ofs" "Mur5_optimized2014_2_file2.fs"
		;
connectAttr "Mur5_optimized2014_2_file2.oa" "Mur5_optimized2014_2_bump2d2.bv";
connectAttr "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.oc" "Mur5_optimized2014_4_lambert8.c"
		;
connectAttr "Mur5_optimized2014_4_bump2d1.o" "Mur5_optimized2014_4_lambert8.n";
connectAttr "Mur5_optimized2014_4_ReflectionMap.oc" "Mur5_optimized2014_4_lambert8.rc"
		;
connectAttr "Mur5_optimized2014_4_lambert8.oc" "Mur5_optimized2014_4_polySurface33SG.ss"
		;
connectAttr "Mur5_optimized2014_4_polySurface33SG.msg" "Mur5_optimized2014_4_materialInfo1.sg"
		;
connectAttr "Mur5_optimized2014_4_lambert8.msg" "Mur5_optimized2014_4_materialInfo1.m"
		;
connectAttr "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" "Mur5_optimized2014_4_materialInfo1.t"
		 -na;
connectAttr "Mur5_optimized2014_4_place2dTexture1.o" "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture1.ofu" "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture1.ofv" "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture1.rf" "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture1.reu" "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture1.rev" "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture1.vt1" "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture1.vt2" "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture1.vt3" "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture1.vc1" "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture1.ofs" "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "Mur5_optimized2014_4_bump2d1.bv"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture2.o" "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture2.ofu" "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture2.ofv" "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture2.rf" "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture2.reu" "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture2.rev" "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture2.vt1" "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture2.vt2" "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture2.vt3" "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture2.vc1" "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture2.ofs" "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture3.o" "Mur5_optimized2014_4_ReflectionMap.uv"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture3.ofu" "Mur5_optimized2014_4_ReflectionMap.ofu"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture3.ofv" "Mur5_optimized2014_4_ReflectionMap.ofv"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture3.rf" "Mur5_optimized2014_4_ReflectionMap.rf"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture3.reu" "Mur5_optimized2014_4_ReflectionMap.reu"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture3.rev" "Mur5_optimized2014_4_ReflectionMap.rev"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture3.vt1" "Mur5_optimized2014_4_ReflectionMap.vt1"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture3.vt2" "Mur5_optimized2014_4_ReflectionMap.vt2"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture3.vt3" "Mur5_optimized2014_4_ReflectionMap.vt3"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture3.vc1" "Mur5_optimized2014_4_ReflectionMap.vc1"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture3.ofs" "Mur5_optimized2014_4_ReflectionMap.fs"
		;
connectAttr "Mur5_optimized2014_4_file1.oc" "Mur5_optimized2014_4_lambert9.c";
connectAttr "Mur5_optimized2014_4_file1.ot" "Mur5_optimized2014_4_lambert9.it";
connectAttr "Mur5_optimized2014_4_bump2d2.o" "Mur5_optimized2014_4_lambert9.n";
connectAttr "Mur5_optimized2014_4_lambert9.oc" "Mur5_optimized2014_4_lambert9SG.ss"
		;
connectAttr "Mur5_optimized2014_4_lambert9SG.msg" "Mur5_optimized2014_4_materialInfo2.sg"
		;
connectAttr "Mur5_optimized2014_4_lambert9.msg" "Mur5_optimized2014_4_materialInfo2.m"
		;
connectAttr "Mur5_optimized2014_4_file1.msg" "Mur5_optimized2014_4_materialInfo2.t"
		 -na;
connectAttr "Mur5_optimized2014_4_place2dTexture4.c" "Mur5_optimized2014_4_file1.c"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.tf" "Mur5_optimized2014_4_file1.tf"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.rf" "Mur5_optimized2014_4_file1.rf"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.mu" "Mur5_optimized2014_4_file1.mu"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.mv" "Mur5_optimized2014_4_file1.mv"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.s" "Mur5_optimized2014_4_file1.s"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.wu" "Mur5_optimized2014_4_file1.wu"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.wv" "Mur5_optimized2014_4_file1.wv"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.re" "Mur5_optimized2014_4_file1.re"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.of" "Mur5_optimized2014_4_file1.of"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.r" "Mur5_optimized2014_4_file1.ro"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.n" "Mur5_optimized2014_4_file1.n"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.vt1" "Mur5_optimized2014_4_file1.vt1"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.vt2" "Mur5_optimized2014_4_file1.vt2"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.vt3" "Mur5_optimized2014_4_file1.vt3"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.vc1" "Mur5_optimized2014_4_file1.vc1"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.o" "Mur5_optimized2014_4_file1.uv"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture4.ofs" "Mur5_optimized2014_4_file1.fs"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.c" "Mur5_optimized2014_4_file2.c"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.tf" "Mur5_optimized2014_4_file2.tf"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.rf" "Mur5_optimized2014_4_file2.rf"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.mu" "Mur5_optimized2014_4_file2.mu"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.mv" "Mur5_optimized2014_4_file2.mv"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.s" "Mur5_optimized2014_4_file2.s"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.wu" "Mur5_optimized2014_4_file2.wu"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.wv" "Mur5_optimized2014_4_file2.wv"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.re" "Mur5_optimized2014_4_file2.re"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.of" "Mur5_optimized2014_4_file2.of"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.r" "Mur5_optimized2014_4_file2.ro"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.n" "Mur5_optimized2014_4_file2.n"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.vt1" "Mur5_optimized2014_4_file2.vt1"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.vt2" "Mur5_optimized2014_4_file2.vt2"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.vt3" "Mur5_optimized2014_4_file2.vt3"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.vc1" "Mur5_optimized2014_4_file2.vc1"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.o" "Mur5_optimized2014_4_file2.uv"
		;
connectAttr "Mur5_optimized2014_4_place2dTexture5.ofs" "Mur5_optimized2014_4_file2.fs"
		;
connectAttr "Mur5_optimized2014_4_file2.oa" "Mur5_optimized2014_4_bump2d2.bv";
connectAttr "lambert9_Flattened_Diffuse.oc" "lambert10.c";
connectAttr "bump2d3.o" "lambert10.n";
connectAttr "lambert9_Flattened_Opacity.ot" "lambert10.it";
connectAttr "Mur5_optimized2014_4_ReflectionMap.oc" "lambert10.rc";
connectAttr "lambert10.oc" "wallSG.ss";
connectAttr "wallSG.msg" "materialInfo3.sg";
connectAttr "lambert10.msg" "materialInfo3.m";
connectAttr "lambert9_Flattened_Diffuse.msg" "materialInfo3.t" -na;
connectAttr "place2dTexture6.o" "lambert9_Flattened_Diffuse.uv";
connectAttr "place2dTexture6.ofu" "lambert9_Flattened_Diffuse.ofu";
connectAttr "place2dTexture6.ofv" "lambert9_Flattened_Diffuse.ofv";
connectAttr "place2dTexture6.rf" "lambert9_Flattened_Diffuse.rf";
connectAttr "place2dTexture6.reu" "lambert9_Flattened_Diffuse.reu";
connectAttr "place2dTexture6.rev" "lambert9_Flattened_Diffuse.rev";
connectAttr "place2dTexture6.vt1" "lambert9_Flattened_Diffuse.vt1";
connectAttr "place2dTexture6.vt2" "lambert9_Flattened_Diffuse.vt2";
connectAttr "place2dTexture6.vt3" "lambert9_Flattened_Diffuse.vt3";
connectAttr "place2dTexture6.vc1" "lambert9_Flattened_Diffuse.vc1";
connectAttr "place2dTexture6.ofs" "lambert9_Flattened_Diffuse.fs";
connectAttr "lambert9_Flattened_BumpFBXASC032Map.oa" "bump2d3.bv";
connectAttr "place2dTexture7.o" "lambert9_Flattened_BumpFBXASC032Map.uv";
connectAttr "place2dTexture7.ofu" "lambert9_Flattened_BumpFBXASC032Map.ofu";
connectAttr "place2dTexture7.ofv" "lambert9_Flattened_BumpFBXASC032Map.ofv";
connectAttr "place2dTexture7.rf" "lambert9_Flattened_BumpFBXASC032Map.rf";
connectAttr "place2dTexture7.reu" "lambert9_Flattened_BumpFBXASC032Map.reu";
connectAttr "place2dTexture7.rev" "lambert9_Flattened_BumpFBXASC032Map.rev";
connectAttr "place2dTexture7.vt1" "lambert9_Flattened_BumpFBXASC032Map.vt1";
connectAttr "place2dTexture7.vt2" "lambert9_Flattened_BumpFBXASC032Map.vt2";
connectAttr "place2dTexture7.vt3" "lambert9_Flattened_BumpFBXASC032Map.vt3";
connectAttr "place2dTexture7.vc1" "lambert9_Flattened_BumpFBXASC032Map.vc1";
connectAttr "place2dTexture7.ofs" "lambert9_Flattened_BumpFBXASC032Map.fs";
connectAttr "place2dTexture8.o" "lambert9_Flattened_Opacity.uv";
connectAttr "place2dTexture8.ofu" "lambert9_Flattened_Opacity.ofu";
connectAttr "place2dTexture8.ofv" "lambert9_Flattened_Opacity.ofv";
connectAttr "place2dTexture8.rf" "lambert9_Flattened_Opacity.rf";
connectAttr "place2dTexture8.reu" "lambert9_Flattened_Opacity.reu";
connectAttr "place2dTexture8.rev" "lambert9_Flattened_Opacity.rev";
connectAttr "place2dTexture8.vt1" "lambert9_Flattened_Opacity.vt1";
connectAttr "place2dTexture8.vt2" "lambert9_Flattened_Opacity.vt2";
connectAttr "place2dTexture8.vt3" "lambert9_Flattened_Opacity.vt3";
connectAttr "place2dTexture8.vc1" "lambert9_Flattened_Opacity.vc1";
connectAttr "place2dTexture8.ofs" "lambert9_Flattened_Opacity.fs";
connectAttr "lambert11_Flattened_Diffuse.oc" "lambert11.c";
connectAttr "bump2d4.o" "lambert11.n";
connectAttr "lambert11_Flattened_Opacity.ot" "lambert11.it";
connectAttr "ReflectionMap.oc" "lambert11.rc";
connectAttr "lambert11.oc" "wallSG1.ss";
connectAttr "wallSG1.msg" "materialInfo4.sg";
connectAttr "lambert11.msg" "materialInfo4.m";
connectAttr "lambert11_Flattened_Diffuse.msg" "materialInfo4.t" -na;
connectAttr "lambert11_Flattened_BumpFBXASC032Map.oa" "bump2d4.bv";
connectAttr "place2dTexture9.o" "lambert11_Flattened_Diffuse.uv";
connectAttr "place2dTexture9.ofu" "lambert11_Flattened_Diffuse.ofu";
connectAttr "place2dTexture9.ofv" "lambert11_Flattened_Diffuse.ofv";
connectAttr "place2dTexture9.rf" "lambert11_Flattened_Diffuse.rf";
connectAttr "place2dTexture9.reu" "lambert11_Flattened_Diffuse.reu";
connectAttr "place2dTexture9.rev" "lambert11_Flattened_Diffuse.rev";
connectAttr "place2dTexture9.vt1" "lambert11_Flattened_Diffuse.vt1";
connectAttr "place2dTexture9.vt2" "lambert11_Flattened_Diffuse.vt2";
connectAttr "place2dTexture9.vt3" "lambert11_Flattened_Diffuse.vt3";
connectAttr "place2dTexture9.vc1" "lambert11_Flattened_Diffuse.vc1";
connectAttr "place2dTexture9.ofs" "lambert11_Flattened_Diffuse.fs";
connectAttr "place2dTexture10.o" "lambert11_Flattened_BumpFBXASC032Map.uv";
connectAttr "place2dTexture10.ofu" "lambert11_Flattened_BumpFBXASC032Map.ofu";
connectAttr "place2dTexture10.ofv" "lambert11_Flattened_BumpFBXASC032Map.ofv";
connectAttr "place2dTexture10.rf" "lambert11_Flattened_BumpFBXASC032Map.rf";
connectAttr "place2dTexture10.reu" "lambert11_Flattened_BumpFBXASC032Map.reu";
connectAttr "place2dTexture10.rev" "lambert11_Flattened_BumpFBXASC032Map.rev";
connectAttr "place2dTexture10.vt1" "lambert11_Flattened_BumpFBXASC032Map.vt1";
connectAttr "place2dTexture10.vt2" "lambert11_Flattened_BumpFBXASC032Map.vt2";
connectAttr "place2dTexture10.vt3" "lambert11_Flattened_BumpFBXASC032Map.vt3";
connectAttr "place2dTexture10.vc1" "lambert11_Flattened_BumpFBXASC032Map.vc1";
connectAttr "place2dTexture10.ofs" "lambert11_Flattened_BumpFBXASC032Map.fs";
connectAttr "place2dTexture11.o" "lambert11_Flattened_Opacity.uv";
connectAttr "place2dTexture11.ofu" "lambert11_Flattened_Opacity.ofu";
connectAttr "place2dTexture11.ofv" "lambert11_Flattened_Opacity.ofv";
connectAttr "place2dTexture11.rf" "lambert11_Flattened_Opacity.rf";
connectAttr "place2dTexture11.reu" "lambert11_Flattened_Opacity.reu";
connectAttr "place2dTexture11.rev" "lambert11_Flattened_Opacity.rev";
connectAttr "place2dTexture11.vt1" "lambert11_Flattened_Opacity.vt1";
connectAttr "place2dTexture11.vt2" "lambert11_Flattened_Opacity.vt2";
connectAttr "place2dTexture11.vt3" "lambert11_Flattened_Opacity.vt3";
connectAttr "place2dTexture11.vc1" "lambert11_Flattened_Opacity.vc1";
connectAttr "place2dTexture11.ofs" "lambert11_Flattened_Opacity.fs";
connectAttr "lambert12_Flattened_Diffuse.oc" "lambert12.c";
connectAttr "bump2d5.o" "lambert12.n";
connectAttr "lambert12_Flattened_Opacity.ot" "lambert12.it";
connectAttr "ReflectionMap.oc" "lambert12.rc";
connectAttr "lambert12.oc" "wallSG2.ss";
connectAttr "wallSG2.msg" "materialInfo5.sg";
connectAttr "lambert12.msg" "materialInfo5.m";
connectAttr "lambert12_Flattened_Diffuse.msg" "materialInfo5.t" -na;
connectAttr "place2dTexture12.o" "lambert12_Flattened_Diffuse.uv";
connectAttr "place2dTexture12.ofu" "lambert12_Flattened_Diffuse.ofu";
connectAttr "place2dTexture12.ofv" "lambert12_Flattened_Diffuse.ofv";
connectAttr "place2dTexture12.rf" "lambert12_Flattened_Diffuse.rf";
connectAttr "place2dTexture12.reu" "lambert12_Flattened_Diffuse.reu";
connectAttr "place2dTexture12.rev" "lambert12_Flattened_Diffuse.rev";
connectAttr "place2dTexture12.vt1" "lambert12_Flattened_Diffuse.vt1";
connectAttr "place2dTexture12.vt2" "lambert12_Flattened_Diffuse.vt2";
connectAttr "place2dTexture12.vt3" "lambert12_Flattened_Diffuse.vt3";
connectAttr "place2dTexture12.vc1" "lambert12_Flattened_Diffuse.vc1";
connectAttr "place2dTexture12.ofs" "lambert12_Flattened_Diffuse.fs";
connectAttr "lambert12_Flattened_BumpFBXASC032Map.oa" "bump2d5.bv";
connectAttr "place2dTexture13.o" "lambert12_Flattened_BumpFBXASC032Map.uv";
connectAttr "place2dTexture13.ofu" "lambert12_Flattened_BumpFBXASC032Map.ofu";
connectAttr "place2dTexture13.ofv" "lambert12_Flattened_BumpFBXASC032Map.ofv";
connectAttr "place2dTexture13.rf" "lambert12_Flattened_BumpFBXASC032Map.rf";
connectAttr "place2dTexture13.reu" "lambert12_Flattened_BumpFBXASC032Map.reu";
connectAttr "place2dTexture13.rev" "lambert12_Flattened_BumpFBXASC032Map.rev";
connectAttr "place2dTexture13.vt1" "lambert12_Flattened_BumpFBXASC032Map.vt1";
connectAttr "place2dTexture13.vt2" "lambert12_Flattened_BumpFBXASC032Map.vt2";
connectAttr "place2dTexture13.vt3" "lambert12_Flattened_BumpFBXASC032Map.vt3";
connectAttr "place2dTexture13.vc1" "lambert12_Flattened_BumpFBXASC032Map.vc1";
connectAttr "place2dTexture13.ofs" "lambert12_Flattened_BumpFBXASC032Map.fs";
connectAttr "place2dTexture14.o" "lambert12_Flattened_Opacity.uv";
connectAttr "place2dTexture14.ofu" "lambert12_Flattened_Opacity.ofu";
connectAttr "place2dTexture14.ofv" "lambert12_Flattened_Opacity.ofv";
connectAttr "place2dTexture14.rf" "lambert12_Flattened_Opacity.rf";
connectAttr "place2dTexture14.reu" "lambert12_Flattened_Opacity.reu";
connectAttr "place2dTexture14.rev" "lambert12_Flattened_Opacity.rev";
connectAttr "place2dTexture14.vt1" "lambert12_Flattened_Opacity.vt1";
connectAttr "place2dTexture14.vt2" "lambert12_Flattened_Opacity.vt2";
connectAttr "place2dTexture14.vt3" "lambert12_Flattened_Opacity.vt3";
connectAttr "place2dTexture14.vc1" "lambert12_Flattened_Opacity.vc1";
connectAttr "place2dTexture14.ofs" "lambert12_Flattened_Opacity.fs";
connectAttr "murPort4_2014_tri:lambert12_Flattened_Diffuse.oc" "murPort4_2014_tri:lambert12.c"
		;
connectAttr "murPort4_2014_tri:bump2d1.o" "murPort4_2014_tri:lambert12.n";
connectAttr "murPort4_2014_tri:ReflectionMap.oc" "murPort4_2014_tri:lambert12.rc"
		;
connectAttr "murPort4_2014_tri:lambert12.oc" "murPort4_2014_tri:wallBlockSG.ss";
connectAttr "murPort4_2014_tri:wallBlockSG.msg" "murPort4_2014_tri:materialInfo1.sg"
		;
connectAttr "murPort4_2014_tri:lambert12.msg" "murPort4_2014_tri:materialInfo1.m"
		;
connectAttr "murPort4_2014_tri:lambert12_Flattened_Diffuse.msg" "murPort4_2014_tri:materialInfo1.t"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture1.o" "murPort4_2014_tri:lambert12_Flattened_Diffuse.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture1.ofu" "murPort4_2014_tri:lambert12_Flattened_Diffuse.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture1.ofv" "murPort4_2014_tri:lambert12_Flattened_Diffuse.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture1.rf" "murPort4_2014_tri:lambert12_Flattened_Diffuse.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture1.reu" "murPort4_2014_tri:lambert12_Flattened_Diffuse.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture1.rev" "murPort4_2014_tri:lambert12_Flattened_Diffuse.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture1.vt1" "murPort4_2014_tri:lambert12_Flattened_Diffuse.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture1.vt2" "murPort4_2014_tri:lambert12_Flattened_Diffuse.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture1.vt3" "murPort4_2014_tri:lambert12_Flattened_Diffuse.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture1.vc1" "murPort4_2014_tri:lambert12_Flattened_Diffuse.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture1.ofs" "murPort4_2014_tri:lambert12_Flattened_Diffuse.fs"
		;
connectAttr "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.oa" "murPort4_2014_tri:bump2d1.bv"
		;
connectAttr "murPort4_2014_tri:place2dTexture2.o" "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture2.ofu" "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture2.ofv" "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture2.rf" "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture2.reu" "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture2.rev" "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture2.vt1" "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture2.vt2" "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture2.vt3" "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture2.vc1" "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture2.ofs" "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:place2dTexture3.o" "murPort4_2014_tri:ReflectionMap.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture3.ofu" "murPort4_2014_tri:ReflectionMap.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture3.ofv" "murPort4_2014_tri:ReflectionMap.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture3.rf" "murPort4_2014_tri:ReflectionMap.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture3.reu" "murPort4_2014_tri:ReflectionMap.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture3.rev" "murPort4_2014_tri:ReflectionMap.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture3.vt1" "murPort4_2014_tri:ReflectionMap.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture3.vt2" "murPort4_2014_tri:ReflectionMap.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture3.vt3" "murPort4_2014_tri:ReflectionMap.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture3.vc1" "murPort4_2014_tri:ReflectionMap.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture3.ofs" "murPort4_2014_tri:ReflectionMap.fs"
		;
connectAttr "murPort4_2014_tri:lambert13_Flattened_Diffuse.oc" "murPort4_2014_tri:lambert13.c"
		;
connectAttr "murPort4_2014_tri:bump2d2.o" "murPort4_2014_tri:lambert13.n";
connectAttr "murPort4_2014_tri:ReflectionMap.oc" "murPort4_2014_tri:lambert13.rc"
		;
connectAttr "murPort4_2014_tri:lambert13.oc" "murPort4_2014_tri:wallBlockSG1.ss"
		;
connectAttr "murPort4_2014_tri:wallBlockSG1.msg" "murPort4_2014_tri:materialInfo2.sg"
		;
connectAttr "murPort4_2014_tri:lambert13.msg" "murPort4_2014_tri:materialInfo2.m"
		;
connectAttr "murPort4_2014_tri:lambert13_Flattened_Diffuse.msg" "murPort4_2014_tri:materialInfo2.t"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture4.o" "murPort4_2014_tri:lambert13_Flattened_Diffuse.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture4.ofu" "murPort4_2014_tri:lambert13_Flattened_Diffuse.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture4.ofv" "murPort4_2014_tri:lambert13_Flattened_Diffuse.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture4.rf" "murPort4_2014_tri:lambert13_Flattened_Diffuse.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture4.reu" "murPort4_2014_tri:lambert13_Flattened_Diffuse.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture4.rev" "murPort4_2014_tri:lambert13_Flattened_Diffuse.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture4.vt1" "murPort4_2014_tri:lambert13_Flattened_Diffuse.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture4.vt2" "murPort4_2014_tri:lambert13_Flattened_Diffuse.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture4.vt3" "murPort4_2014_tri:lambert13_Flattened_Diffuse.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture4.vc1" "murPort4_2014_tri:lambert13_Flattened_Diffuse.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture4.ofs" "murPort4_2014_tri:lambert13_Flattened_Diffuse.fs"
		;
connectAttr "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.oa" "murPort4_2014_tri:bump2d2.bv"
		;
connectAttr "murPort4_2014_tri:place2dTexture5.o" "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture5.ofu" "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture5.ofv" "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture5.rf" "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture5.reu" "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture5.rev" "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture5.vt1" "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture5.vt2" "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture5.vt3" "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture5.vc1" "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture5.ofs" "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.oc" "murPort4_2014_tri:lambert8.c"
		;
connectAttr "murPort4_2014_tri:mur22227_bump2d1.o" "murPort4_2014_tri:lambert8.n"
		;
connectAttr "murPort4_2014_tri:mur22227_ReflectionMap.oc" "murPort4_2014_tri:lambert8.rc"
		;
connectAttr "murPort4_2014_tri:lambert8.oc" "murPort4_2014_tri:polySurface33SG.ss"
		;
connectAttr "murPort4_2014_tri:polySurface33SG.msg" "murPort4_2014_tri:mur22227_materialInfo1.sg"
		;
connectAttr "murPort4_2014_tri:lambert8.msg" "murPort4_2014_tri:mur22227_materialInfo1.m"
		;
connectAttr "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.msg" "murPort4_2014_tri:mur22227_materialInfo1.t"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture1.o" "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture1.ofu" "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture1.ofv" "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture1.rf" "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture1.reu" "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture1.rev" "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture1.vt1" "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture1.vt2" "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture1.vt3" "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture1.vc1" "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture1.ofs" "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murPort4_2014_tri:mur22227_bump2d1.bv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture2.o" "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture2.ofu" "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture2.ofv" "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture2.rf" "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture2.reu" "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture2.rev" "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture2.vt1" "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture2.vt2" "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture2.vt3" "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture2.vc1" "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture2.ofs" "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture3.o" "murPort4_2014_tri:mur22227_ReflectionMap.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture3.ofu" "murPort4_2014_tri:mur22227_ReflectionMap.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture3.ofv" "murPort4_2014_tri:mur22227_ReflectionMap.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture3.rf" "murPort4_2014_tri:mur22227_ReflectionMap.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture3.reu" "murPort4_2014_tri:mur22227_ReflectionMap.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture3.rev" "murPort4_2014_tri:mur22227_ReflectionMap.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture3.vt1" "murPort4_2014_tri:mur22227_ReflectionMap.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture3.vt2" "murPort4_2014_tri:mur22227_ReflectionMap.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture3.vt3" "murPort4_2014_tri:mur22227_ReflectionMap.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture3.vc1" "murPort4_2014_tri:mur22227_ReflectionMap.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture3.ofs" "murPort4_2014_tri:mur22227_ReflectionMap.fs"
		;
connectAttr "murPort4_2014_tri:file1.oc" "murPort4_2014_tri:lambert9.c";
connectAttr "murPort4_2014_tri:file1.ot" "murPort4_2014_tri:lambert9.it";
connectAttr "murPort4_2014_tri:mur22227_bump2d2.o" "murPort4_2014_tri:lambert9.n"
		;
connectAttr "murPort4_2014_tri:lambert9.oc" "murPort4_2014_tri:lambert9SG.ss";
connectAttr "murPort4_2014_tri:lambert9SG.msg" "murPort4_2014_tri:mur22227_materialInfo2.sg"
		;
connectAttr "murPort4_2014_tri:lambert9.msg" "murPort4_2014_tri:mur22227_materialInfo2.m"
		;
connectAttr "murPort4_2014_tri:file1.msg" "murPort4_2014_tri:mur22227_materialInfo2.t"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.c" "murPort4_2014_tri:file1.c"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.tf" "murPort4_2014_tri:file1.tf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.rf" "murPort4_2014_tri:file1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.mu" "murPort4_2014_tri:file1.mu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.mv" "murPort4_2014_tri:file1.mv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.s" "murPort4_2014_tri:file1.s"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.wu" "murPort4_2014_tri:file1.wu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.wv" "murPort4_2014_tri:file1.wv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.re" "murPort4_2014_tri:file1.re"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.of" "murPort4_2014_tri:file1.of"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.r" "murPort4_2014_tri:file1.ro"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.n" "murPort4_2014_tri:file1.n"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.vt1" "murPort4_2014_tri:file1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.vt2" "murPort4_2014_tri:file1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.vt3" "murPort4_2014_tri:file1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.vc1" "murPort4_2014_tri:file1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.o" "murPort4_2014_tri:file1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.ofs" "murPort4_2014_tri:file1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.c" "murPort4_2014_tri:file2.c"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.tf" "murPort4_2014_tri:file2.tf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.rf" "murPort4_2014_tri:file2.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.mu" "murPort4_2014_tri:file2.mu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.mv" "murPort4_2014_tri:file2.mv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.s" "murPort4_2014_tri:file2.s"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.wu" "murPort4_2014_tri:file2.wu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.wv" "murPort4_2014_tri:file2.wv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.re" "murPort4_2014_tri:file2.re"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.of" "murPort4_2014_tri:file2.of"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.r" "murPort4_2014_tri:file2.ro"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.n" "murPort4_2014_tri:file2.n"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.vt1" "murPort4_2014_tri:file2.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.vt2" "murPort4_2014_tri:file2.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.vt3" "murPort4_2014_tri:file2.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.vc1" "murPort4_2014_tri:file2.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.o" "murPort4_2014_tri:file2.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.ofs" "murPort4_2014_tri:file2.fs"
		;
connectAttr "murPort4_2014_tri:file2.oa" "murPort4_2014_tri:mur22227_bump2d2.bv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.oc" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8.c"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_bump2d1.o" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8.n"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.oc" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8.rc"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_lambert8.oc" "murPort4_2014_tri:Mur5_optimized2014_2_polySurface33SG.ss"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_polySurface33SG.msg" "murPort4_2014_tri:Mur5_optimized2014_2_materialInfo1.sg"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_lambert8.msg" "murPort4_2014_tri:Mur5_optimized2014_2_materialInfo1.m"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" "murPort4_2014_tri:Mur5_optimized2014_2_materialInfo1.t"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.o" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.ofu" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.ofv" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.rf" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.reu" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.rev" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.vt1" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.vt2" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.vt3" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.vc1" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.ofs" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murPort4_2014_tri:Mur5_optimized2014_2_bump2d1.bv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.o" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.ofu" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.ofv" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.rf" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.reu" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.rev" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.vt1" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.vt2" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.vt3" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.vc1" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.ofs" "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.o" "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.uv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.ofu" "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.ofu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.ofv" "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.ofv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.rf" "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.rf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.reu" "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.reu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.rev" "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.rev"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.vt1" "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.vt1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.vt2" "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.vt2"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.vt3" "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.vt3"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.vc1" "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.vc1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.ofs" "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.fs"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_file1.oc" "murPort4_2014_tri:Mur5_optimized2014_2_lambert9.c"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_file1.ot" "murPort4_2014_tri:Mur5_optimized2014_2_lambert9.it"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_bump2d2.o" "murPort4_2014_tri:Mur5_optimized2014_2_lambert9.n"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_lambert9.oc" "murPort4_2014_tri:Mur5_optimized2014_2_lambert9SG.ss"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_lambert9SG.msg" "murPort4_2014_tri:Mur5_optimized2014_2_materialInfo2.sg"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_lambert9.msg" "murPort4_2014_tri:Mur5_optimized2014_2_materialInfo2.m"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_file1.msg" "murPort4_2014_tri:Mur5_optimized2014_2_materialInfo2.t"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.c" "murPort4_2014_tri:Mur5_optimized2014_2_file1.c"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.tf" "murPort4_2014_tri:Mur5_optimized2014_2_file1.tf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.rf" "murPort4_2014_tri:Mur5_optimized2014_2_file1.rf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.mu" "murPort4_2014_tri:Mur5_optimized2014_2_file1.mu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.mv" "murPort4_2014_tri:Mur5_optimized2014_2_file1.mv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.s" "murPort4_2014_tri:Mur5_optimized2014_2_file1.s"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.wu" "murPort4_2014_tri:Mur5_optimized2014_2_file1.wu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.wv" "murPort4_2014_tri:Mur5_optimized2014_2_file1.wv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.re" "murPort4_2014_tri:Mur5_optimized2014_2_file1.re"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.of" "murPort4_2014_tri:Mur5_optimized2014_2_file1.of"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.r" "murPort4_2014_tri:Mur5_optimized2014_2_file1.ro"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.n" "murPort4_2014_tri:Mur5_optimized2014_2_file1.n"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.vt1" "murPort4_2014_tri:Mur5_optimized2014_2_file1.vt1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.vt2" "murPort4_2014_tri:Mur5_optimized2014_2_file1.vt2"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.vt3" "murPort4_2014_tri:Mur5_optimized2014_2_file1.vt3"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.vc1" "murPort4_2014_tri:Mur5_optimized2014_2_file1.vc1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.o" "murPort4_2014_tri:Mur5_optimized2014_2_file1.uv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.ofs" "murPort4_2014_tri:Mur5_optimized2014_2_file1.fs"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.c" "murPort4_2014_tri:Mur5_optimized2014_2_file2.c"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.tf" "murPort4_2014_tri:Mur5_optimized2014_2_file2.tf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.rf" "murPort4_2014_tri:Mur5_optimized2014_2_file2.rf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.mu" "murPort4_2014_tri:Mur5_optimized2014_2_file2.mu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.mv" "murPort4_2014_tri:Mur5_optimized2014_2_file2.mv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.s" "murPort4_2014_tri:Mur5_optimized2014_2_file2.s"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.wu" "murPort4_2014_tri:Mur5_optimized2014_2_file2.wu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.wv" "murPort4_2014_tri:Mur5_optimized2014_2_file2.wv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.re" "murPort4_2014_tri:Mur5_optimized2014_2_file2.re"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.of" "murPort4_2014_tri:Mur5_optimized2014_2_file2.of"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.r" "murPort4_2014_tri:Mur5_optimized2014_2_file2.ro"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.n" "murPort4_2014_tri:Mur5_optimized2014_2_file2.n"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.vt1" "murPort4_2014_tri:Mur5_optimized2014_2_file2.vt1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.vt2" "murPort4_2014_tri:Mur5_optimized2014_2_file2.vt2"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.vt3" "murPort4_2014_tri:Mur5_optimized2014_2_file2.vt3"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.vc1" "murPort4_2014_tri:Mur5_optimized2014_2_file2.vc1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.o" "murPort4_2014_tri:Mur5_optimized2014_2_file2.uv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.ofs" "murPort4_2014_tri:Mur5_optimized2014_2_file2.fs"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_file2.oa" "murPort4_2014_tri:Mur5_optimized2014_2_bump2d2.bv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.oc" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8.c"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_bump2d1.o" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8.n"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.oc" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8.rc"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_lambert8.oc" "murPort4_2014_tri:Mur5_optimized2014_4_polySurface33SG.ss"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_polySurface33SG.msg" "murPort4_2014_tri:Mur5_optimized2014_4_materialInfo1.sg"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_lambert8.msg" "murPort4_2014_tri:Mur5_optimized2014_4_materialInfo1.m"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" "murPort4_2014_tri:Mur5_optimized2014_4_materialInfo1.t"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.o" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.ofu" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.ofv" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.rf" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.reu" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.rev" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.vt1" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.vt2" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.vt3" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.vc1" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.ofs" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murPort4_2014_tri:Mur5_optimized2014_4_bump2d1.bv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.o" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.ofu" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.ofv" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.rf" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.reu" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.rev" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.vt1" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.vt2" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.vt3" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.vc1" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.ofs" "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.o" "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.uv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.ofu" "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.ofu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.ofv" "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.ofv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.rf" "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.rf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.reu" "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.reu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.rev" "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.rev"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.vt1" "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.vt1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.vt2" "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.vt2"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.vt3" "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.vt3"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.vc1" "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.vc1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.ofs" "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.fs"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_file1.oc" "murPort4_2014_tri:Mur5_optimized2014_4_lambert9.c"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_file1.ot" "murPort4_2014_tri:Mur5_optimized2014_4_lambert9.it"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_bump2d2.o" "murPort4_2014_tri:Mur5_optimized2014_4_lambert9.n"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_lambert9.oc" "murPort4_2014_tri:Mur5_optimized2014_4_lambert9SG.ss"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_lambert9SG.msg" "murPort4_2014_tri:Mur5_optimized2014_4_materialInfo2.sg"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_lambert9.msg" "murPort4_2014_tri:Mur5_optimized2014_4_materialInfo2.m"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_file1.msg" "murPort4_2014_tri:Mur5_optimized2014_4_materialInfo2.t"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.c" "murPort4_2014_tri:Mur5_optimized2014_4_file1.c"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.tf" "murPort4_2014_tri:Mur5_optimized2014_4_file1.tf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.rf" "murPort4_2014_tri:Mur5_optimized2014_4_file1.rf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.mu" "murPort4_2014_tri:Mur5_optimized2014_4_file1.mu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.mv" "murPort4_2014_tri:Mur5_optimized2014_4_file1.mv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.s" "murPort4_2014_tri:Mur5_optimized2014_4_file1.s"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.wu" "murPort4_2014_tri:Mur5_optimized2014_4_file1.wu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.wv" "murPort4_2014_tri:Mur5_optimized2014_4_file1.wv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.re" "murPort4_2014_tri:Mur5_optimized2014_4_file1.re"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.of" "murPort4_2014_tri:Mur5_optimized2014_4_file1.of"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.r" "murPort4_2014_tri:Mur5_optimized2014_4_file1.ro"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.n" "murPort4_2014_tri:Mur5_optimized2014_4_file1.n"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.vt1" "murPort4_2014_tri:Mur5_optimized2014_4_file1.vt1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.vt2" "murPort4_2014_tri:Mur5_optimized2014_4_file1.vt2"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.vt3" "murPort4_2014_tri:Mur5_optimized2014_4_file1.vt3"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.vc1" "murPort4_2014_tri:Mur5_optimized2014_4_file1.vc1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.o" "murPort4_2014_tri:Mur5_optimized2014_4_file1.uv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.ofs" "murPort4_2014_tri:Mur5_optimized2014_4_file1.fs"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.c" "murPort4_2014_tri:Mur5_optimized2014_4_file2.c"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.tf" "murPort4_2014_tri:Mur5_optimized2014_4_file2.tf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.rf" "murPort4_2014_tri:Mur5_optimized2014_4_file2.rf"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.mu" "murPort4_2014_tri:Mur5_optimized2014_4_file2.mu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.mv" "murPort4_2014_tri:Mur5_optimized2014_4_file2.mv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.s" "murPort4_2014_tri:Mur5_optimized2014_4_file2.s"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.wu" "murPort4_2014_tri:Mur5_optimized2014_4_file2.wu"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.wv" "murPort4_2014_tri:Mur5_optimized2014_4_file2.wv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.re" "murPort4_2014_tri:Mur5_optimized2014_4_file2.re"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.of" "murPort4_2014_tri:Mur5_optimized2014_4_file2.of"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.r" "murPort4_2014_tri:Mur5_optimized2014_4_file2.ro"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.n" "murPort4_2014_tri:Mur5_optimized2014_4_file2.n"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.vt1" "murPort4_2014_tri:Mur5_optimized2014_4_file2.vt1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.vt2" "murPort4_2014_tri:Mur5_optimized2014_4_file2.vt2"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.vt3" "murPort4_2014_tri:Mur5_optimized2014_4_file2.vt3"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.vc1" "murPort4_2014_tri:Mur5_optimized2014_4_file2.vc1"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.o" "murPort4_2014_tri:Mur5_optimized2014_4_file2.uv"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.ofs" "murPort4_2014_tri:Mur5_optimized2014_4_file2.fs"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_file2.oa" "murPort4_2014_tri:Mur5_optimized2014_4_bump2d2.bv"
		;
connectAttr "murPort4_2014_tri:lambert9_Flattened_Diffuse.oc" "murPort4_2014_tri:lambert10.c"
		;
connectAttr "murPort4_2014_tri:bump2d3.o" "murPort4_2014_tri:lambert10.n";
connectAttr "murPort4_2014_tri:lambert9_Flattened_Opacity.ot" "murPort4_2014_tri:lambert10.it"
		;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.oc" "murPort4_2014_tri:lambert10.rc"
		;
connectAttr "murPort4_2014_tri:lambert10.oc" "murPort4_2014_tri:wallSG.ss";
connectAttr "murPort4_2014_tri:wallSG.msg" "murPort4_2014_tri:materialInfo3.sg";
connectAttr "murPort4_2014_tri:lambert10.msg" "murPort4_2014_tri:materialInfo3.m"
		;
connectAttr "murPort4_2014_tri:lambert9_Flattened_Diffuse.msg" "murPort4_2014_tri:materialInfo3.t"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture6.o" "murPort4_2014_tri:lambert9_Flattened_Diffuse.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture6.ofu" "murPort4_2014_tri:lambert9_Flattened_Diffuse.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture6.ofv" "murPort4_2014_tri:lambert9_Flattened_Diffuse.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture6.rf" "murPort4_2014_tri:lambert9_Flattened_Diffuse.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture6.reu" "murPort4_2014_tri:lambert9_Flattened_Diffuse.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture6.rev" "murPort4_2014_tri:lambert9_Flattened_Diffuse.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture6.vt1" "murPort4_2014_tri:lambert9_Flattened_Diffuse.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture6.vt2" "murPort4_2014_tri:lambert9_Flattened_Diffuse.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture6.vt3" "murPort4_2014_tri:lambert9_Flattened_Diffuse.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture6.vc1" "murPort4_2014_tri:lambert9_Flattened_Diffuse.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture6.ofs" "murPort4_2014_tri:lambert9_Flattened_Diffuse.fs"
		;
connectAttr "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.oa" "murPort4_2014_tri:bump2d3.bv"
		;
connectAttr "murPort4_2014_tri:place2dTexture7.o" "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture7.ofu" "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture7.ofv" "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture7.rf" "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture7.reu" "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture7.rev" "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture7.vt1" "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture7.vt2" "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture7.vt3" "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture7.vc1" "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture7.ofs" "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:place2dTexture8.o" "murPort4_2014_tri:lambert9_Flattened_Opacity.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture8.ofu" "murPort4_2014_tri:lambert9_Flattened_Opacity.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture8.ofv" "murPort4_2014_tri:lambert9_Flattened_Opacity.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture8.rf" "murPort4_2014_tri:lambert9_Flattened_Opacity.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture8.reu" "murPort4_2014_tri:lambert9_Flattened_Opacity.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture8.rev" "murPort4_2014_tri:lambert9_Flattened_Opacity.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture8.vt1" "murPort4_2014_tri:lambert9_Flattened_Opacity.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture8.vt2" "murPort4_2014_tri:lambert9_Flattened_Opacity.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture8.vt3" "murPort4_2014_tri:lambert9_Flattened_Opacity.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture8.vc1" "murPort4_2014_tri:lambert9_Flattened_Opacity.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture8.ofs" "murPort4_2014_tri:lambert9_Flattened_Opacity.fs"
		;
connectAttr "murPort4_2014_tri:lambert11_Flattened_Diffuse.oc" "murPort4_2014_tri:lambert11.c"
		;
connectAttr "murPort4_2014_tri:bump2d4.o" "murPort4_2014_tri:lambert11.n";
connectAttr "murPort4_2014_tri:lambert11_Flattened_Opacity.ot" "murPort4_2014_tri:lambert11.it"
		;
connectAttr "murPort4_2014_tri:mur22227_ReflectionMap.oc" "murPort4_2014_tri:lambert11.rc"
		;
connectAttr "murPort4_2014_tri:lambert11.oc" "murPort4_2014_tri:wallSG1.ss";
connectAttr "murPort4_2014_tri:wallSG1.msg" "murPort4_2014_tri:materialInfo4.sg"
		;
connectAttr "murPort4_2014_tri:lambert11.msg" "murPort4_2014_tri:materialInfo4.m"
		;
connectAttr "murPort4_2014_tri:lambert11_Flattened_Diffuse.msg" "murPort4_2014_tri:materialInfo4.t"
		 -na;
connectAttr "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.oa" "murPort4_2014_tri:bump2d4.bv"
		;
connectAttr "murPort4_2014_tri:place2dTexture9.o" "murPort4_2014_tri:lambert11_Flattened_Diffuse.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture9.ofu" "murPort4_2014_tri:lambert11_Flattened_Diffuse.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture9.ofv" "murPort4_2014_tri:lambert11_Flattened_Diffuse.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture9.rf" "murPort4_2014_tri:lambert11_Flattened_Diffuse.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture9.reu" "murPort4_2014_tri:lambert11_Flattened_Diffuse.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture9.rev" "murPort4_2014_tri:lambert11_Flattened_Diffuse.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture9.vt1" "murPort4_2014_tri:lambert11_Flattened_Diffuse.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture9.vt2" "murPort4_2014_tri:lambert11_Flattened_Diffuse.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture9.vt3" "murPort4_2014_tri:lambert11_Flattened_Diffuse.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture9.vc1" "murPort4_2014_tri:lambert11_Flattened_Diffuse.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture9.ofs" "murPort4_2014_tri:lambert11_Flattened_Diffuse.fs"
		;
connectAttr "murPort4_2014_tri:place2dTexture10.o" "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture10.ofu" "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture10.ofv" "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture10.rf" "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture10.reu" "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture10.rev" "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture10.vt1" "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture10.vt2" "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture10.vt3" "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture10.vc1" "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture10.ofs" "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:place2dTexture11.o" "murPort4_2014_tri:lambert11_Flattened_Opacity.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture11.ofu" "murPort4_2014_tri:lambert11_Flattened_Opacity.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture11.ofv" "murPort4_2014_tri:lambert11_Flattened_Opacity.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture11.rf" "murPort4_2014_tri:lambert11_Flattened_Opacity.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture11.reu" "murPort4_2014_tri:lambert11_Flattened_Opacity.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture11.rev" "murPort4_2014_tri:lambert11_Flattened_Opacity.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture11.vt1" "murPort4_2014_tri:lambert11_Flattened_Opacity.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture11.vt2" "murPort4_2014_tri:lambert11_Flattened_Opacity.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture11.vt3" "murPort4_2014_tri:lambert11_Flattened_Opacity.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture11.vc1" "murPort4_2014_tri:lambert11_Flattened_Opacity.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture11.ofs" "murPort4_2014_tri:lambert11_Flattened_Opacity.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.oc" "murPort4_2014_tri:mur22227_lambert12.c"
		;
connectAttr "murPort4_2014_tri:bump2d5.o" "murPort4_2014_tri:mur22227_lambert12.n"
		;
connectAttr "murPort4_2014_tri:lambert12_Flattened_Opacity.ot" "murPort4_2014_tri:mur22227_lambert12.it"
		;
connectAttr "murPort4_2014_tri:mur22227_ReflectionMap.oc" "murPort4_2014_tri:mur22227_lambert12.rc"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert12.oc" "murPort4_2014_tri:wallSG2.ss"
		;
connectAttr "murPort4_2014_tri:wallSG2.msg" "murPort4_2014_tri:materialInfo5.sg"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert12.msg" "murPort4_2014_tri:materialInfo5.m"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.msg" "murPort4_2014_tri:materialInfo5.t"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture12.o" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture12.ofu" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture12.ofv" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture12.rf" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture12.reu" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture12.rev" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture12.vt1" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture12.vt2" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture12.vt3" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture12.vc1" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture12.ofs" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.fs"
		;
connectAttr "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.oa" "murPort4_2014_tri:bump2d5.bv"
		;
connectAttr "murPort4_2014_tri:place2dTexture13.o" "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture13.ofu" "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture13.ofv" "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture13.rf" "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture13.reu" "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture13.rev" "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture13.vt1" "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture13.vt2" "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture13.vt3" "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture13.vc1" "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture13.ofs" "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:place2dTexture14.o" "murPort4_2014_tri:lambert12_Flattened_Opacity.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture14.ofu" "murPort4_2014_tri:lambert12_Flattened_Opacity.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture14.ofv" "murPort4_2014_tri:lambert12_Flattened_Opacity.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture14.rf" "murPort4_2014_tri:lambert12_Flattened_Opacity.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture14.reu" "murPort4_2014_tri:lambert12_Flattened_Opacity.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture14.rev" "murPort4_2014_tri:lambert12_Flattened_Opacity.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture14.vt1" "murPort4_2014_tri:lambert12_Flattened_Opacity.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture14.vt2" "murPort4_2014_tri:lambert12_Flattened_Opacity.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture14.vt3" "murPort4_2014_tri:lambert12_Flattened_Opacity.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture14.vc1" "murPort4_2014_tri:lambert12_Flattened_Opacity.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture14.ofs" "murPort4_2014_tri:lambert12_Flattened_Opacity.fs"
		;
connectAttr "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.oc" "murPort4_2014_tri:lambert16.c"
		;
connectAttr "murPort4_2014_tri:bump2d6.o" "murPort4_2014_tri:lambert16.n";
connectAttr "murPort4_2014_tri:ReflectionMap.oc" "murPort4_2014_tri:lambert16.rc"
		;
connectAttr "murPort4_2014_tri:lambert16.oc" "murPort4_2014_tri:wallBlockSG2.ss"
		;
connectAttr "murPort4_2014_tri:wallBlockSG2.msg" "murPort4_2014_tri:materialInfo6.sg"
		;
connectAttr "murPort4_2014_tri:lambert16.msg" "murPort4_2014_tri:materialInfo6.m"
		;
connectAttr "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.msg" "murPort4_2014_tri:materialInfo6.t"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture15.o" "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture15.ofu" "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture15.ofv" "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture15.rf" "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture15.reu" "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture15.rev" "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture15.vt1" "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture15.vt2" "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture15.vt3" "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture15.vc1" "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture15.ofs" "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.oa" "murPort4_2014_tri:bump2d6.bv"
		;
connectAttr "murPort4_2014_tri:place2dTexture16.o" "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture16.ofu" "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture16.ofv" "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture16.rf" "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture16.reu" "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture16.rev" "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture16.vt1" "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture16.vt2" "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture16.vt3" "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture16.vc1" "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture16.ofs" "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.oc" "murPort4_2014_tri:lambert17.c"
		;
connectAttr "murPort4_2014_tri:bump2d7.o" "murPort4_2014_tri:lambert17.n";
connectAttr "murPort4_2014_tri:ReflectionMap.oc" "murPort4_2014_tri:lambert17.rc"
		;
connectAttr "murPort4_2014_tri:lambert17.oc" "murPort4_2014_tri:wallBlockSG3.ss"
		;
connectAttr "murPort4_2014_tri:wallBlockSG3.msg" "murPort4_2014_tri:materialInfo7.sg"
		;
connectAttr "murPort4_2014_tri:lambert17.msg" "murPort4_2014_tri:materialInfo7.m"
		;
connectAttr "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.msg" "murPort4_2014_tri:materialInfo7.t"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture17.o" "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture17.ofu" "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture17.ofv" "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture17.rf" "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture17.reu" "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture17.rev" "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture17.vt1" "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture17.vt2" "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture17.vt3" "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture17.vc1" "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture17.ofs" "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.oa" "murPort4_2014_tri:bump2d7.bv"
		;
connectAttr "murPort4_2014_tri:place2dTexture18.o" "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture18.ofu" "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture18.ofv" "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture18.rf" "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture18.reu" "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture18.rev" "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture18.vt1" "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture18.vt2" "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture18.vt3" "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture18.vc1" "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture18.ofs" "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.oc" "murPort4_2014_tri:murBlock6_2014_lambert12.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d1.o" "murPort4_2014_tri:murBlock6_2014_lambert12.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_ReflectionMap.oc" "murPort4_2014_tri:murBlock6_2014_lambert12.rc"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert12.oc" "murPort4_2014_tri:murBlock6_2014_wallBlockSG.ss"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallBlockSG.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo1.sg"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert12.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo1.m"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo1.t"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture1.o" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture1.ofu" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture1.ofv" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture1.rf" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture1.reu" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture1.rev" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture1.vt1" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture1.vt2" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture1.vt3" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture1.vc1" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture1.ofs" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.oa" "murPort4_2014_tri:murBlock6_2014_bump2d1.bv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture2.o" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture2.ofu" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture2.ofv" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture2.rf" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture2.reu" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture2.rev" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture2.vt1" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture2.vt2" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture2.vt3" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture2.vc1" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture2.ofs" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture3.o" "murPort4_2014_tri:murBlock6_2014_ReflectionMap.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture3.ofu" "murPort4_2014_tri:murBlock6_2014_ReflectionMap.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture3.ofv" "murPort4_2014_tri:murBlock6_2014_ReflectionMap.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture3.rf" "murPort4_2014_tri:murBlock6_2014_ReflectionMap.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture3.reu" "murPort4_2014_tri:murBlock6_2014_ReflectionMap.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture3.rev" "murPort4_2014_tri:murBlock6_2014_ReflectionMap.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture3.vt1" "murPort4_2014_tri:murBlock6_2014_ReflectionMap.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture3.vt2" "murPort4_2014_tri:murBlock6_2014_ReflectionMap.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture3.vt3" "murPort4_2014_tri:murBlock6_2014_ReflectionMap.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture3.vc1" "murPort4_2014_tri:murBlock6_2014_ReflectionMap.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture3.ofs" "murPort4_2014_tri:murBlock6_2014_ReflectionMap.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.oc" "murPort4_2014_tri:murBlock6_2014_lambert13.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d2.o" "murPort4_2014_tri:murBlock6_2014_lambert13.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_ReflectionMap.oc" "murPort4_2014_tri:murBlock6_2014_lambert13.rc"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert13.oc" "murPort4_2014_tri:murBlock6_2014_wallBlockSG1.ss"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallBlockSG1.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo2.sg"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert13.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo2.m"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo2.t"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture4.o" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture4.ofu" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture4.ofv" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture4.rf" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture4.reu" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture4.rev" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture4.vt1" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture4.vt2" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture4.vt3" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture4.vc1" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture4.ofs" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.oa" "murPort4_2014_tri:murBlock6_2014_bump2d2.bv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture5.o" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture5.ofu" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture5.ofv" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture5.rf" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture5.reu" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture5.rev" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture5.vt1" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture5.vt2" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture5.vt3" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture5.vc1" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture5.ofs" "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.oc" "murPort4_2014_tri:murBlock6_2014_lambert8.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_bump2d1.o" "murPort4_2014_tri:murBlock6_2014_lambert8.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.oc" "murPort4_2014_tri:murBlock6_2014_lambert8.rc"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert8.oc" "murPort4_2014_tri:murBlock6_2014_polySurface33SG.ss"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_polySurface33SG.msg" "murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo1.sg"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert8.msg" "murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo1.m"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.msg" "murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo1.t"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.o" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.ofu" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.ofv" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.rf" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.reu" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.rev" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.vt1" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.vt2" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.vt3" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.vc1" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.ofs" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murPort4_2014_tri:murBlock6_2014_mur22227_bump2d1.bv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.o" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.ofu" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.ofv" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.rf" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.reu" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.rev" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.vt1" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.vt2" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.vt3" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.vc1" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.ofs" "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.o" "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.ofu" "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.ofv" "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.rf" "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.reu" "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.rev" "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.vt1" "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.vt2" "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.vt3" "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.vc1" "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.ofs" "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_file1.oc" "murPort4_2014_tri:murBlock6_2014_lambert9.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_file1.ot" "murPort4_2014_tri:murBlock6_2014_lambert9.it"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_bump2d2.o" "murPort4_2014_tri:murBlock6_2014_lambert9.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert9.oc" "murPort4_2014_tri:murBlock6_2014_lambert9SG.ss"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert9SG.msg" "murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo2.sg"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert9.msg" "murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo2.m"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_file1.msg" "murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo2.t"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.c" "murPort4_2014_tri:murBlock6_2014_file1.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.tf" "murPort4_2014_tri:murBlock6_2014_file1.tf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.rf" "murPort4_2014_tri:murBlock6_2014_file1.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.mu" "murPort4_2014_tri:murBlock6_2014_file1.mu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.mv" "murPort4_2014_tri:murBlock6_2014_file1.mv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.s" "murPort4_2014_tri:murBlock6_2014_file1.s"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.wu" "murPort4_2014_tri:murBlock6_2014_file1.wu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.wv" "murPort4_2014_tri:murBlock6_2014_file1.wv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.re" "murPort4_2014_tri:murBlock6_2014_file1.re"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.of" "murPort4_2014_tri:murBlock6_2014_file1.of"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.r" "murPort4_2014_tri:murBlock6_2014_file1.ro"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.n" "murPort4_2014_tri:murBlock6_2014_file1.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.vt1" "murPort4_2014_tri:murBlock6_2014_file1.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.vt2" "murPort4_2014_tri:murBlock6_2014_file1.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.vt3" "murPort4_2014_tri:murBlock6_2014_file1.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.vc1" "murPort4_2014_tri:murBlock6_2014_file1.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.o" "murPort4_2014_tri:murBlock6_2014_file1.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.ofs" "murPort4_2014_tri:murBlock6_2014_file1.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.c" "murPort4_2014_tri:murBlock6_2014_file2.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.tf" "murPort4_2014_tri:murBlock6_2014_file2.tf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.rf" "murPort4_2014_tri:murBlock6_2014_file2.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.mu" "murPort4_2014_tri:murBlock6_2014_file2.mu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.mv" "murPort4_2014_tri:murBlock6_2014_file2.mv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.s" "murPort4_2014_tri:murBlock6_2014_file2.s"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.wu" "murPort4_2014_tri:murBlock6_2014_file2.wu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.wv" "murPort4_2014_tri:murBlock6_2014_file2.wv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.re" "murPort4_2014_tri:murBlock6_2014_file2.re"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.of" "murPort4_2014_tri:murBlock6_2014_file2.of"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.r" "murPort4_2014_tri:murBlock6_2014_file2.ro"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.n" "murPort4_2014_tri:murBlock6_2014_file2.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.vt1" "murPort4_2014_tri:murBlock6_2014_file2.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.vt2" "murPort4_2014_tri:murBlock6_2014_file2.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.vt3" "murPort4_2014_tri:murBlock6_2014_file2.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.vc1" "murPort4_2014_tri:murBlock6_2014_file2.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.o" "murPort4_2014_tri:murBlock6_2014_file2.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.ofs" "murPort4_2014_tri:murBlock6_2014_file2.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_file2.oa" "murPort4_2014_tri:murBlock6_2014_mur22227_bump2d2.bv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.oc" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d1.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.oc" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8.rc"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8.oc" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_polySurface33SG.ss"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_polySurface33SG.msg" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo1.sg"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8.msg" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo1.m"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo1.t"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.ofu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.ofv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.rf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.reu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.rev" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.vt1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.vt2" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.vt3" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.vc1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.ofs" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d1.bv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.ofu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.ofv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.rf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.reu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.rev" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.vt1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.vt2" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.vt3" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.vc1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.ofs" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.ofu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.ofv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.rf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.reu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.rev" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.vt1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.vt2" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.vt3" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.vc1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.ofs" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.oc" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.ot" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9.it"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d2.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9.oc" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9SG.ss"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9SG.msg" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo2.sg"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9.msg" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo2.m"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.msg" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo2.t"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.c" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.tf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.tf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.rf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.mu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.mu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.mv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.mv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.s" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.s"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.wu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.wu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.wv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.wv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.re" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.re"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.of" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.of"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.r" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.ro"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.n" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.vt1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.vt2" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.vt3" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.vc1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.ofs" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.c" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.tf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.tf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.rf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.mu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.mu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.mv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.mv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.s" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.s"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.wu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.wu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.wv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.wv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.re" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.re"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.of" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.of"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.r" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.ro"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.n" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.vt1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.vt2" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.vt3" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.vc1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.ofs" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.oa" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d2.bv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.oc" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d1.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.oc" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8.rc"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8.oc" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_polySurface33SG.ss"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_polySurface33SG.msg" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo1.sg"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8.msg" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo1.m"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo1.t"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.ofu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.ofv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.rf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.reu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.rev" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.vt1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.vt2" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.vt3" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.vc1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.ofs" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d1.bv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.ofu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.ofv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.rf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.reu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.rev" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.vt1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.vt2" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.vt3" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.vc1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.ofs" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.ofu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.ofv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.rf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.reu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.rev" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.vt1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.vt2" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.vt3" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.vc1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.ofs" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.oc" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.ot" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9.it"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d2.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9.oc" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9SG.ss"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9SG.msg" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo2.sg"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9.msg" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo2.m"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.msg" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo2.t"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.c" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.tf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.tf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.rf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.mu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.mu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.mv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.mv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.s" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.s"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.wu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.wu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.wv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.wv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.re" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.re"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.of" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.of"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.r" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.ro"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.n" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.vt1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.vt2" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.vt3" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.vc1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.ofs" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.c" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.tf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.tf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.rf" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.mu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.mu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.mv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.mv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.s" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.s"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.wu" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.wu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.wv" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.wv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.re" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.re"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.of" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.of"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.r" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.ro"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.n" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.vt1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.vt2" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.vt3" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.vc1" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.o" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.ofs" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.oa" "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d2.bv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.oc" "murPort4_2014_tri:murBlock6_2014_lambert10.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d3.o" "murPort4_2014_tri:murBlock6_2014_lambert10.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.ot" "murPort4_2014_tri:murBlock6_2014_lambert10.it"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.oc" "murPort4_2014_tri:murBlock6_2014_lambert10.rc"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert10.oc" "murPort4_2014_tri:murBlock6_2014_wallSG.ss"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallSG.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo3.sg"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert10.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo3.m"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo3.t"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture6.o" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture6.ofu" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture6.ofv" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture6.rf" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture6.reu" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture6.rev" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture6.vt1" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture6.vt2" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture6.vt3" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture6.vc1" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture6.ofs" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.oa" "murPort4_2014_tri:murBlock6_2014_bump2d3.bv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture7.o" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture7.ofu" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture7.ofv" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture7.rf" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture7.reu" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture7.rev" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture7.vt1" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture7.vt2" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture7.vt3" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture7.vc1" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture7.ofs" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture8.o" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture8.ofu" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture8.ofv" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture8.rf" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture8.reu" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture8.rev" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture8.vt1" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture8.vt2" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture8.vt3" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture8.vc1" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture8.ofs" "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.oc" "murPort4_2014_tri:murBlock6_2014_lambert11.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d4.o" "murPort4_2014_tri:murBlock6_2014_lambert11.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.ot" "murPort4_2014_tri:murBlock6_2014_lambert11.it"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.oc" "murPort4_2014_tri:murBlock6_2014_lambert11.rc"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert11.oc" "murPort4_2014_tri:murBlock6_2014_wallSG1.ss"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallSG1.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo4.sg"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert11.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo4.m"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo4.t"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.oa" "murPort4_2014_tri:murBlock6_2014_bump2d4.bv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture9.o" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture9.ofu" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture9.ofv" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture9.rf" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture9.reu" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture9.rev" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture9.vt1" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture9.vt2" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture9.vt3" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture9.vc1" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture9.ofs" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture10.o" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture10.ofu" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture10.ofv" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture10.rf" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture10.reu" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture10.rev" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture10.vt1" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture10.vt2" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture10.vt3" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture10.vc1" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture10.ofs" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture11.o" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture11.ofu" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture11.ofv" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture11.rf" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture11.reu" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture11.rev" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture11.vt1" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture11.vt2" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture11.vt3" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture11.vc1" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture11.ofs" "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.oc" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d5.o" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.ot" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.it"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.oc" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.rc"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.oc" "murPort4_2014_tri:murBlock6_2014_wallSG2.ss"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallSG2.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo5.sg"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo5.m"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo5.t"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture12.o" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture12.ofu" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture12.ofv" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture12.rf" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture12.reu" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture12.rev" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture12.vt1" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture12.vt2" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture12.vt3" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture12.vc1" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture12.ofs" "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.oa" "murPort4_2014_tri:murBlock6_2014_bump2d5.bv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture13.o" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture13.ofu" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture13.ofv" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture13.rf" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture13.reu" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture13.rev" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture13.vt1" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture13.vt2" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture13.vt3" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture13.vc1" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture13.ofs" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture14.o" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture14.ofu" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture14.ofv" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture14.rf" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture14.reu" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture14.rev" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture14.vt1" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture14.vt2" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture14.vt3" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture14.vc1" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture14.ofs" "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.oc" "murPort4_2014_tri:murBlock6_2014_lambert16.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d6.o" "murPort4_2014_tri:murBlock6_2014_lambert16.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_ReflectionMap.oc" "murPort4_2014_tri:murBlock6_2014_lambert16.rc"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert16.oc" "murPort4_2014_tri:murBlock6_2014_wallBlockSG2.ss"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallBlockSG2.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo6.sg"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert16.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo6.m"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo6.t"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture15.o" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture15.ofu" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture15.ofv" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture15.rf" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture15.reu" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture15.rev" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture15.vt1" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture15.vt2" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture15.vt3" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture15.vc1" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture15.ofs" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.oa" "murPort4_2014_tri:murBlock6_2014_bump2d6.bv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture16.o" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture16.ofu" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture16.ofv" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture16.rf" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture16.reu" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture16.rev" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture16.vt1" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture16.vt2" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture16.vt3" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture16.vc1" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture16.ofs" "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.oc" "murPort4_2014_tri:murBlock6_2014_lambert17.c"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d7.o" "murPort4_2014_tri:murBlock6_2014_lambert17.n"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_ReflectionMap.oc" "murPort4_2014_tri:murBlock6_2014_lambert17.rc"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert17.oc" "murPort4_2014_tri:murBlock6_2014_wallBlockSG3.ss"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallBlockSG3.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo7.sg"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert17.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo7.m"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.msg" "murPort4_2014_tri:murBlock6_2014_materialInfo7.t"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture17.o" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture17.ofu" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture17.ofv" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture17.rf" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture17.reu" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture17.rev" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture17.vt1" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture17.vt2" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture17.vt3" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture17.vc1" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture17.ofs" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.oa" "murPort4_2014_tri:murBlock6_2014_bump2d7.bv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture18.o" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture18.ofu" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture18.ofv" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture18.rf" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture18.reu" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture18.rev" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture18.vt1" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture18.vt2" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture18.vt3" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture18.vc1" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture18.ofs" "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.oc" "murPort4_2014_tri:mur22227_lambert8.c"
		;
connectAttr "murPort4_2014_tri:mur22227_bump2d3.o" "murPort4_2014_tri:mur22227_lambert8.n"
		;
connectAttr "murPort4_2014_tri:mur22227_ReflectionMap1.oc" "murPort4_2014_tri:mur22227_lambert8.rc"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert8.oc" "murPort4_2014_tri:mur22227_polySurface33SG.ss"
		;
connectAttr "murPort4_2014_tri:mur22227_polySurface33SG.msg" "murPort4_2014_tri:mur22227_materialInfo3.sg"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert8.msg" "murPort4_2014_tri:mur22227_materialInfo3.m"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.msg" "murPort4_2014_tri:mur22227_materialInfo3.t"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture6.o" "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture6.ofu" "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture6.ofv" "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture6.rf" "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture6.reu" "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture6.rev" "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture6.vt1" "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture6.vt2" "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture6.vt3" "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture6.vc1" "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture6.ofs" "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murPort4_2014_tri:mur22227_bump2d3.bv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture7.o" "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture7.ofu" "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture7.ofv" "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture7.rf" "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture7.reu" "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture7.rev" "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture7.vt1" "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture7.vt2" "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture7.vt3" "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture7.vc1" "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture7.ofs" "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture8.o" "murPort4_2014_tri:mur22227_ReflectionMap1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture8.ofu" "murPort4_2014_tri:mur22227_ReflectionMap1.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture8.ofv" "murPort4_2014_tri:mur22227_ReflectionMap1.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture8.rf" "murPort4_2014_tri:mur22227_ReflectionMap1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture8.reu" "murPort4_2014_tri:mur22227_ReflectionMap1.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture8.rev" "murPort4_2014_tri:mur22227_ReflectionMap1.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture8.vt1" "murPort4_2014_tri:mur22227_ReflectionMap1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture8.vt2" "murPort4_2014_tri:mur22227_ReflectionMap1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture8.vt3" "murPort4_2014_tri:mur22227_ReflectionMap1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture8.vc1" "murPort4_2014_tri:mur22227_ReflectionMap1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture8.ofs" "murPort4_2014_tri:mur22227_ReflectionMap1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_file1.oc" "murPort4_2014_tri:mur22227_lambert9.c"
		;
connectAttr "murPort4_2014_tri:mur22227_file1.ot" "murPort4_2014_tri:mur22227_lambert9.it"
		;
connectAttr "murPort4_2014_tri:mur22227_bump2d4.o" "murPort4_2014_tri:mur22227_lambert9.n"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert9.oc" "murPort4_2014_tri:mur22227_lambert9SG.ss"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert9SG.msg" "murPort4_2014_tri:mur22227_materialInfo4.sg"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert9.msg" "murPort4_2014_tri:mur22227_materialInfo4.m"
		;
connectAttr "murPort4_2014_tri:mur22227_file1.msg" "murPort4_2014_tri:mur22227_materialInfo4.t"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.c" "murPort4_2014_tri:mur22227_file1.c"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.tf" "murPort4_2014_tri:mur22227_file1.tf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.rf" "murPort4_2014_tri:mur22227_file1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.mu" "murPort4_2014_tri:mur22227_file1.mu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.mv" "murPort4_2014_tri:mur22227_file1.mv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.s" "murPort4_2014_tri:mur22227_file1.s"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.wu" "murPort4_2014_tri:mur22227_file1.wu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.wv" "murPort4_2014_tri:mur22227_file1.wv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.re" "murPort4_2014_tri:mur22227_file1.re"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.of" "murPort4_2014_tri:mur22227_file1.of"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.r" "murPort4_2014_tri:mur22227_file1.ro"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.n" "murPort4_2014_tri:mur22227_file1.n"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.vt1" "murPort4_2014_tri:mur22227_file1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.vt2" "murPort4_2014_tri:mur22227_file1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.vt3" "murPort4_2014_tri:mur22227_file1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.vc1" "murPort4_2014_tri:mur22227_file1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.o" "murPort4_2014_tri:mur22227_file1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.ofs" "murPort4_2014_tri:mur22227_file1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.c" "murPort4_2014_tri:mur22227_file2.c"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.tf" "murPort4_2014_tri:mur22227_file2.tf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.rf" "murPort4_2014_tri:mur22227_file2.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.mu" "murPort4_2014_tri:mur22227_file2.mu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.mv" "murPort4_2014_tri:mur22227_file2.mv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.s" "murPort4_2014_tri:mur22227_file2.s"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.wu" "murPort4_2014_tri:mur22227_file2.wu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.wv" "murPort4_2014_tri:mur22227_file2.wv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.re" "murPort4_2014_tri:mur22227_file2.re"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.of" "murPort4_2014_tri:mur22227_file2.of"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.r" "murPort4_2014_tri:mur22227_file2.ro"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.n" "murPort4_2014_tri:mur22227_file2.n"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.vt1" "murPort4_2014_tri:mur22227_file2.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.vt2" "murPort4_2014_tri:mur22227_file2.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.vt3" "murPort4_2014_tri:mur22227_file2.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.vc1" "murPort4_2014_tri:mur22227_file2.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.o" "murPort4_2014_tri:mur22227_file2.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.ofs" "murPort4_2014_tri:mur22227_file2.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_file2.oa" "murPort4_2014_tri:mur22227_bump2d4.bv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.oc" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8.c"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d1.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8.n"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.oc" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8.rc"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8.oc" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_polySurface33SG.ss"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_polySurface33SG.msg" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo1.sg"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8.msg" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo1.m"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo1.t"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.ofu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.ofv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.rf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.reu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.rev" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.vt1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.vt2" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.vt3" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.vc1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.ofs" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d1.bv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.ofu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.ofv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.rf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.reu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.rev" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.vt1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.vt2" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.vt3" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.vc1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.ofs" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.ofu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.ofv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.rf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.reu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.rev" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.vt1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.vt2" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.vt3" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.vc1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.ofs" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.oc" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9.c"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.ot" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9.it"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d2.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9.n"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9.oc" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9SG.ss"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9SG.msg" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo2.sg"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9.msg" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo2.m"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.msg" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo2.t"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.c" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.c"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.tf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.tf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.rf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.mu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.mu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.mv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.mv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.s" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.s"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.wu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.wu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.wv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.wv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.re" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.re"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.of" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.of"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.r" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.ro"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.n" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.n"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.vt1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.vt2" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.vt3" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.vc1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.ofs" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.c" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.c"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.tf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.tf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.rf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.mu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.mu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.mv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.mv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.s" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.s"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.wu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.wu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.wv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.wv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.re" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.re"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.of" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.of"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.r" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.ro"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.n" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.n"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.vt1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.vt2" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.vt3" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.vc1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.ofs" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.oa" "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d2.bv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.oc" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8.c"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d1.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8.n"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.oc" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8.rc"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8.oc" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_polySurface33SG.ss"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_polySurface33SG.msg" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo1.sg"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8.msg" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo1.m"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo1.t"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.ofu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.ofv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.rf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.reu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.rev" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.vt1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.vt2" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.vt3" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.vc1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.ofs" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d1.bv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.ofu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.ofv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.rf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.reu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.rev" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.vt1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.vt2" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.vt3" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.vc1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.ofs" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.ofu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.ofv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.rf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.reu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.rev" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.vt1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.vt2" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.vt3" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.vc1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.ofs" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.oc" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9.c"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.ot" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9.it"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d2.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9.n"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9.oc" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9SG.ss"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9SG.msg" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo2.sg"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9.msg" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo2.m"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.msg" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo2.t"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.c" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.c"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.tf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.tf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.rf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.mu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.mu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.mv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.mv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.s" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.s"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.wu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.wu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.wv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.wv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.re" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.re"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.of" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.of"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.r" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.ro"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.n" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.n"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.vt1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.vt2" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.vt3" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.vc1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.ofs" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.c" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.c"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.tf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.tf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.rf" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.mu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.mu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.mv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.mv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.s" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.s"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.wu" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.wu"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.wv" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.wv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.re" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.re"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.of" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.of"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.r" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.ro"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.n" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.n"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.vt1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.vt2" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.vt3" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.vc1" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.o" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.ofs" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.oa" "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d2.bv"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.oc" "murPort4_2014_tri:mur22227_lambert10.c"
		;
connectAttr "murPort4_2014_tri:mur22227_bump2d5.o" "murPort4_2014_tri:mur22227_lambert10.n"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.ot" "murPort4_2014_tri:mur22227_lambert10.it"
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.oc" "murPort4_2014_tri:mur22227_lambert10.rc"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert10.oc" "murPort4_2014_tri:mur22227_wallSG.ss"
		;
connectAttr "murPort4_2014_tri:mur22227_wallSG.msg" "murPort4_2014_tri:mur22227_materialInfo5.sg"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert10.msg" "murPort4_2014_tri:mur22227_materialInfo5.m"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.msg" "murPort4_2014_tri:mur22227_materialInfo5.t"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture11.o" "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture11.ofu" "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture11.ofv" "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture11.rf" "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture11.reu" "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture11.rev" "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture11.vt1" "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture11.vt2" "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture11.vt3" "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture11.vc1" "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture11.ofs" "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.oa" "murPort4_2014_tri:mur22227_bump2d5.bv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture12.o" "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture12.ofu" "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture12.ofv" "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture12.rf" "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture12.reu" "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture12.rev" "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture12.vt1" "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture12.vt2" "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture12.vt3" "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture12.vc1" "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture12.ofs" "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture13.o" "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture13.ofu" "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture13.ofv" "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture13.rf" "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture13.reu" "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture13.rev" "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture13.vt1" "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture13.vt2" "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture13.vt3" "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture13.vc1" "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture13.ofs" "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.oc" "murPort4_2014_tri:mur22227_lambert11.c"
		;
connectAttr "murPort4_2014_tri:mur22227_bump2d6.o" "murPort4_2014_tri:mur22227_lambert11.n"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.ot" "murPort4_2014_tri:mur22227_lambert11.it"
		;
connectAttr "murPort4_2014_tri:mur22227_ReflectionMap1.oc" "murPort4_2014_tri:mur22227_lambert11.rc"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert11.oc" "murPort4_2014_tri:mur22227_wallSG1.ss"
		;
connectAttr "murPort4_2014_tri:mur22227_wallSG1.msg" "murPort4_2014_tri:mur22227_materialInfo6.sg"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert11.msg" "murPort4_2014_tri:mur22227_materialInfo6.m"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.msg" "murPort4_2014_tri:mur22227_materialInfo6.t"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.oa" "murPort4_2014_tri:mur22227_bump2d6.bv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture14.o" "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture14.ofu" "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture14.ofv" "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture14.rf" "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture14.reu" "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture14.rev" "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture14.vt1" "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture14.vt2" "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture14.vt3" "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture14.vc1" "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture14.ofs" "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture15.o" "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture15.ofu" "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture15.ofv" "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture15.rf" "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture15.reu" "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture15.rev" "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture15.vt1" "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture15.vt2" "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture15.vt3" "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture15.vc1" "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture15.ofs" "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture16.o" "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture16.ofu" "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture16.ofv" "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture16.rf" "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture16.reu" "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture16.rev" "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture16.vt1" "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture16.vt2" "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture16.vt3" "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture16.vc1" "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture16.ofs" "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.oc" "murPort4_2014_tri:mur22227_lambert13.c"
		;
connectAttr "murPort4_2014_tri:mur22227_bump2d7.o" "murPort4_2014_tri:mur22227_lambert13.n"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.ot" "murPort4_2014_tri:mur22227_lambert13.it"
		;
connectAttr "murPort4_2014_tri:mur22227_ReflectionMap1.oc" "murPort4_2014_tri:mur22227_lambert13.rc"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert13.oc" "murPort4_2014_tri:mur22227_wallSG2.ss"
		;
connectAttr "murPort4_2014_tri:mur22227_wallSG2.msg" "murPort4_2014_tri:mur22227_materialInfo7.sg"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert13.msg" "murPort4_2014_tri:mur22227_materialInfo7.m"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.msg" "murPort4_2014_tri:mur22227_materialInfo7.t"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture17.o" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture17.ofu" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture17.ofv" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture17.rf" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture17.reu" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture17.rev" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture17.vt1" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture17.vt2" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture17.vt3" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture17.vc1" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture17.ofs" "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.oa" "murPort4_2014_tri:mur22227_bump2d7.bv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture18.o" "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture18.ofu" "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture18.ofv" "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture18.rf" "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture18.reu" "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture18.rev" "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture18.vt1" "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture18.vt2" "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture18.vt3" "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture18.vc1" "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture18.ofs" "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture19.o" "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.uv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture19.ofu" "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.ofu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture19.ofv" "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.ofv"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture19.rf" "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.rf"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture19.reu" "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.reu"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture19.rev" "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.rev"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture19.vt1" "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.vt1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture19.vt2" "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.vt2"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture19.vt3" "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.vt3"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture19.vc1" "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.vc1"
		;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture19.ofs" "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.fs"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1.oc" "murPort4_2014_tri:murPort2:defaultMat.ss"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat.msg" "murPort4_2014_tri:murPort2:materialInfo1.sg"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1.msg" "murPort4_2014_tri:murPort2:materialInfo1.m"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1F.msg" "murPort4_2014_tri:murPort2:materialInfo1.t"
		 -na;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1F.oc" "murPort4_2014_tri:murPort2:defaultMat1.c"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1P2D.c" "murPort4_2014_tri:murPort2:defaultMat1F.c"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1P2D.tf" "murPort4_2014_tri:murPort2:defaultMat1F.tf"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1P2D.rf" "murPort4_2014_tri:murPort2:defaultMat1F.rf"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1P2D.s" "murPort4_2014_tri:murPort2:defaultMat1F.s"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1P2D.wu" "murPort4_2014_tri:murPort2:defaultMat1F.wu"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1P2D.wv" "murPort4_2014_tri:murPort2:defaultMat1F.wv"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1P2D.re" "murPort4_2014_tri:murPort2:defaultMat1F.re"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1P2D.of" "murPort4_2014_tri:murPort2:defaultMat1F.of"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1P2D.r" "murPort4_2014_tri:murPort2:defaultMat1F.ro"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1P2D.o" "murPort4_2014_tri:murPort2:defaultMat1F.uv"
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1P2D.ofs" "murPort4_2014_tri:murPort2:defaultMat1F.fs"
		;
connectAttr "murPort4_2014_tri:file3.oc" "murPort4_2014_tri:lambert18.c";
connectAttr "murPort4_2014_tri:bump2d8.o" "murPort4_2014_tri:lambert18.n";
connectAttr "murPort4_2014_tri:lambert18.oc" "murPort4_2014_tri:lambert18SG.ss";
connectAttr "murPort4_2014_tri:lambert18SG.msg" "murPort4_2014_tri:materialInfo8.sg"
		;
connectAttr "murPort4_2014_tri:lambert18.msg" "murPort4_2014_tri:materialInfo8.m"
		;
connectAttr "murPort4_2014_tri:file3.msg" "murPort4_2014_tri:materialInfo8.t" -na
		;
connectAttr "murPort4_2014_tri:place2dTexture19.c" "murPort4_2014_tri:file3.c";
connectAttr "murPort4_2014_tri:place2dTexture19.tf" "murPort4_2014_tri:file3.tf"
		;
connectAttr "murPort4_2014_tri:place2dTexture19.rf" "murPort4_2014_tri:file3.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture19.mu" "murPort4_2014_tri:file3.mu"
		;
connectAttr "murPort4_2014_tri:place2dTexture19.mv" "murPort4_2014_tri:file3.mv"
		;
connectAttr "murPort4_2014_tri:place2dTexture19.s" "murPort4_2014_tri:file3.s";
connectAttr "murPort4_2014_tri:place2dTexture19.wu" "murPort4_2014_tri:file3.wu"
		;
connectAttr "murPort4_2014_tri:place2dTexture19.wv" "murPort4_2014_tri:file3.wv"
		;
connectAttr "murPort4_2014_tri:place2dTexture19.re" "murPort4_2014_tri:file3.re"
		;
connectAttr "murPort4_2014_tri:place2dTexture19.of" "murPort4_2014_tri:file3.of"
		;
connectAttr "murPort4_2014_tri:place2dTexture19.r" "murPort4_2014_tri:file3.ro";
connectAttr "murPort4_2014_tri:place2dTexture19.n" "murPort4_2014_tri:file3.n";
connectAttr "murPort4_2014_tri:place2dTexture19.vt1" "murPort4_2014_tri:file3.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture19.vt2" "murPort4_2014_tri:file3.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture19.vt3" "murPort4_2014_tri:file3.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture19.vc1" "murPort4_2014_tri:file3.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture19.o" "murPort4_2014_tri:file3.uv";
connectAttr "murPort4_2014_tri:place2dTexture19.ofs" "murPort4_2014_tri:file3.fs"
		;
connectAttr "murPort4_2014_tri:place2dTexture20.c" "murPort4_2014_tri:file4.c";
connectAttr "murPort4_2014_tri:place2dTexture20.tf" "murPort4_2014_tri:file4.tf"
		;
connectAttr "murPort4_2014_tri:place2dTexture20.rf" "murPort4_2014_tri:file4.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture20.mu" "murPort4_2014_tri:file4.mu"
		;
connectAttr "murPort4_2014_tri:place2dTexture20.mv" "murPort4_2014_tri:file4.mv"
		;
connectAttr "murPort4_2014_tri:place2dTexture20.s" "murPort4_2014_tri:file4.s";
connectAttr "murPort4_2014_tri:place2dTexture20.wu" "murPort4_2014_tri:file4.wu"
		;
connectAttr "murPort4_2014_tri:place2dTexture20.wv" "murPort4_2014_tri:file4.wv"
		;
connectAttr "murPort4_2014_tri:place2dTexture20.re" "murPort4_2014_tri:file4.re"
		;
connectAttr "murPort4_2014_tri:place2dTexture20.of" "murPort4_2014_tri:file4.of"
		;
connectAttr "murPort4_2014_tri:place2dTexture20.r" "murPort4_2014_tri:file4.ro";
connectAttr "murPort4_2014_tri:place2dTexture20.n" "murPort4_2014_tri:file4.n";
connectAttr "murPort4_2014_tri:place2dTexture20.vt1" "murPort4_2014_tri:file4.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture20.vt2" "murPort4_2014_tri:file4.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture20.vt3" "murPort4_2014_tri:file4.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture20.vc1" "murPort4_2014_tri:file4.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture20.o" "murPort4_2014_tri:file4.uv";
connectAttr "murPort4_2014_tri:place2dTexture20.ofs" "murPort4_2014_tri:file4.fs"
		;
connectAttr "murPort4_2014_tri:file4.oa" "murPort4_2014_tri:bump2d8.bv";
connectAttr "murPort4_2014_tri:lambert18_Flattened_Diffuse.oc" "murPort4_2014_tri:lambert19.c"
		;
connectAttr "murPort4_2014_tri:bump2d10.o" "murPort4_2014_tri:lambert19.n";
connectAttr "murPort4_2014_tri:ReflectionMap.oc" "murPort4_2014_tri:lambert19.rc"
		;
connectAttr "murPort4_2014_tri:lambert19.oc" "murPort4_2014_tri:polySurface53SG.ss"
		;
connectAttr "murPort4_2014_tri:polySurface53SG.msg" "murPort4_2014_tri:materialInfo9.sg"
		;
connectAttr "murPort4_2014_tri:lambert19.msg" "murPort4_2014_tri:materialInfo9.m"
		;
connectAttr "murPort4_2014_tri:lambert18_Flattened_Diffuse.msg" "murPort4_2014_tri:materialInfo9.t"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture21.o" "murPort4_2014_tri:lambert18_Flattened_Diffuse.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture21.ofu" "murPort4_2014_tri:lambert18_Flattened_Diffuse.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture21.ofv" "murPort4_2014_tri:lambert18_Flattened_Diffuse.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture21.rf" "murPort4_2014_tri:lambert18_Flattened_Diffuse.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture21.reu" "murPort4_2014_tri:lambert18_Flattened_Diffuse.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture21.rev" "murPort4_2014_tri:lambert18_Flattened_Diffuse.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture21.vt1" "murPort4_2014_tri:lambert18_Flattened_Diffuse.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture21.vt2" "murPort4_2014_tri:lambert18_Flattened_Diffuse.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture21.vt3" "murPort4_2014_tri:lambert18_Flattened_Diffuse.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture21.vc1" "murPort4_2014_tri:lambert18_Flattened_Diffuse.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture21.ofs" "murPort4_2014_tri:lambert18_Flattened_Diffuse.fs"
		;
connectAttr "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.oa" "murPort4_2014_tri:bump2d9.bv"
		;
connectAttr "murPort4_2014_tri:place2dTexture22.o" "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "murPort4_2014_tri:place2dTexture22.ofu" "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "murPort4_2014_tri:place2dTexture22.ofv" "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "murPort4_2014_tri:place2dTexture22.rf" "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture22.reu" "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "murPort4_2014_tri:place2dTexture22.rev" "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "murPort4_2014_tri:place2dTexture22.vt1" "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture22.vt2" "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture22.vt3" "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture22.vc1" "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture22.ofs" "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murPort4_2014_tri:hyperView1.msg" "murPort4_2014_tri:nodeEditorPanel1Info.b[0]"
		;
connectAttr "murPort4_2014_tri:hyperLayout1.msg" "murPort4_2014_tri:hyperView1.hl"
		;
connectAttr "murPort4_2014_tri:file5.msg" "murPort4_2014_tri:hyperLayout1.hyp[0].dn"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.msg" "murPort4_2014_tri:hyperLayout1.hyp[1].dn"
		;
connectAttr "murPort4_2014_tri:bump2d10.msg" "murPort4_2014_tri:hyperLayout1.hyp[2].dn"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.c" "murPort4_2014_tri:file5.c";
connectAttr "murPort4_2014_tri:place2dTexture23.tf" "murPort4_2014_tri:file5.tf"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.rf" "murPort4_2014_tri:file5.rf"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.mu" "murPort4_2014_tri:file5.mu"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.mv" "murPort4_2014_tri:file5.mv"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.s" "murPort4_2014_tri:file5.s";
connectAttr "murPort4_2014_tri:place2dTexture23.wu" "murPort4_2014_tri:file5.wu"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.wv" "murPort4_2014_tri:file5.wv"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.re" "murPort4_2014_tri:file5.re"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.of" "murPort4_2014_tri:file5.of"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.r" "murPort4_2014_tri:file5.ro";
connectAttr "murPort4_2014_tri:place2dTexture23.n" "murPort4_2014_tri:file5.n";
connectAttr "murPort4_2014_tri:place2dTexture23.vt1" "murPort4_2014_tri:file5.vt1"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.vt2" "murPort4_2014_tri:file5.vt2"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.vt3" "murPort4_2014_tri:file5.vt3"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.vc1" "murPort4_2014_tri:file5.vc1"
		;
connectAttr "murPort4_2014_tri:place2dTexture23.o" "murPort4_2014_tri:file5.uv";
connectAttr "murPort4_2014_tri:place2dTexture23.ofs" "murPort4_2014_tri:file5.fs"
		;
connectAttr "murPort4_2014_tri:file5.oa" "murPort4_2014_tri:bump2d10.bv";
connectAttr "MurV2exportFromZbrush:defaultMat1.oc" "MurV2exportFromZbrush:defaultMat.ss"
		;
connectAttr "MurV2exportFromZbrush:groupId1.msg" "MurV2exportFromZbrush:defaultMat.gn"
		 -na;
connectAttr "wallShape.iog.og[0]" "MurV2exportFromZbrush:defaultMat.dsm" -na;
connectAttr "MurV2exportFromZbrush:defaultMat.msg" "MurV2exportFromZbrush:materialInfo1.sg"
		;
connectAttr "MurV2exportFromZbrush:defaultMat1.msg" "MurV2exportFromZbrush:materialInfo1.m"
		;
connectAttr "MurV2exportFromZbrush:defaultMat1F.msg" "MurV2exportFromZbrush:materialInfo1.t"
		 -na;
connectAttr "MurV2exportFromZbrush:defaultMat1F.oc" "MurV2exportFromZbrush:defaultMat1.c"
		;
connectAttr "bump2d6.o" "MurV2exportFromZbrush:defaultMat1.n";
connectAttr "MurV2exportFromZbrush:defaultMat1P2D.c" "MurV2exportFromZbrush:defaultMat1F.c"
		;
connectAttr "MurV2exportFromZbrush:defaultMat1P2D.tf" "MurV2exportFromZbrush:defaultMat1F.tf"
		;
connectAttr "MurV2exportFromZbrush:defaultMat1P2D.rf" "MurV2exportFromZbrush:defaultMat1F.rf"
		;
connectAttr "MurV2exportFromZbrush:defaultMat1P2D.s" "MurV2exportFromZbrush:defaultMat1F.s"
		;
connectAttr "MurV2exportFromZbrush:defaultMat1P2D.wu" "MurV2exportFromZbrush:defaultMat1F.wu"
		;
connectAttr "MurV2exportFromZbrush:defaultMat1P2D.wv" "MurV2exportFromZbrush:defaultMat1F.wv"
		;
connectAttr "MurV2exportFromZbrush:defaultMat1P2D.re" "MurV2exportFromZbrush:defaultMat1F.re"
		;
connectAttr "MurV2exportFromZbrush:defaultMat1P2D.of" "MurV2exportFromZbrush:defaultMat1F.of"
		;
connectAttr "MurV2exportFromZbrush:defaultMat1P2D.r" "MurV2exportFromZbrush:defaultMat1F.ro"
		;
connectAttr "MurV2exportFromZbrush:defaultMat1P2D.o" "MurV2exportFromZbrush:defaultMat1F.uv"
		;
connectAttr "MurV2exportFromZbrush:defaultMat1P2D.ofs" "MurV2exportFromZbrush:defaultMat1F.fs"
		;
connectAttr "place2dTexture15.c" "file3.c";
connectAttr "place2dTexture15.tf" "file3.tf";
connectAttr "place2dTexture15.rf" "file3.rf";
connectAttr "place2dTexture15.mu" "file3.mu";
connectAttr "place2dTexture15.mv" "file3.mv";
connectAttr "place2dTexture15.s" "file3.s";
connectAttr "place2dTexture15.wu" "file3.wu";
connectAttr "place2dTexture15.wv" "file3.wv";
connectAttr "place2dTexture15.re" "file3.re";
connectAttr "place2dTexture15.of" "file3.of";
connectAttr "place2dTexture15.r" "file3.ro";
connectAttr "place2dTexture15.n" "file3.n";
connectAttr "place2dTexture15.vt1" "file3.vt1";
connectAttr "place2dTexture15.vt2" "file3.vt2";
connectAttr "place2dTexture15.vt3" "file3.vt3";
connectAttr "place2dTexture15.vc1" "file3.vc1";
connectAttr "place2dTexture15.o" "file3.uv";
connectAttr "place2dTexture15.ofs" "file3.fs";
connectAttr "file3.oa" "bump2d6.bv";
connectAttr "hyperView1.msg" "nodeEditorPanel1Info.b[0]";
connectAttr "hyperLayout1.msg" "hyperView1.hl";
connectAttr "polySurface33SG.pa" ":renderPartition.st" -na;
connectAttr "lambert9SG.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_2_polySurface33SG.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_2_lambert9SG.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_4_polySurface33SG.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_4_lambert9SG.pa" ":renderPartition.st" -na;
connectAttr "wallSG.pa" ":renderPartition.st" -na;
connectAttr "wallSG1.pa" ":renderPartition.st" -na;
connectAttr "wallSG2.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:wallBlockSG.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:wallBlockSG1.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:polySurface33SG.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:lambert9SG.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:wallSG.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:wallSG1.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:wallSG2.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:wallBlockSG2.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:wallBlockSG3.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallBlockSG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallBlockSG1.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallSG.pa" ":renderPartition.st" -na
		;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallSG1.pa" ":renderPartition.st" 
		-na;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallSG2.pa" ":renderPartition.st" 
		-na;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallBlockSG2.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_wallBlockSG3.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert9SG.pa" ":renderPartition.st" -na
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_wallSG.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:mur22227_wallSG1.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:mur22227_wallSG2.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:murPort2:defaultMat.pa" ":renderPartition.st" -na
		;
connectAttr "murPort4_2014_tri:lambert18SG.pa" ":renderPartition.st" -na;
connectAttr "murPort4_2014_tri:polySurface53SG.pa" ":renderPartition.st" -na;
connectAttr "MurV2exportFromZbrush:defaultMat.pa" ":renderPartition.st" -na;
connectAttr "lambert8.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert9.msg" ":defaultShaderList1.s" -na;
connectAttr "Mur5_optimized2014_2_lambert8.msg" ":defaultShaderList1.s" -na;
connectAttr "Mur5_optimized2014_2_lambert9.msg" ":defaultShaderList1.s" -na;
connectAttr "Mur5_optimized2014_4_lambert8.msg" ":defaultShaderList1.s" -na;
connectAttr "Mur5_optimized2014_4_lambert9.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert10.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert11.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert12.msg" ":defaultShaderList1.s" -na;
connectAttr "murPort4_2014_tri:lambert12.msg" ":defaultShaderList1.s" -na;
connectAttr "murPort4_2014_tri:lambert13.msg" ":defaultShaderList1.s" -na;
connectAttr "murPort4_2014_tri:lambert8.msg" ":defaultShaderList1.s" -na;
connectAttr "murPort4_2014_tri:lambert9.msg" ":defaultShaderList1.s" -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:lambert10.msg" ":defaultShaderList1.s" -na;
connectAttr "murPort4_2014_tri:lambert11.msg" ":defaultShaderList1.s" -na;
connectAttr "murPort4_2014_tri:mur22227_lambert12.msg" ":defaultShaderList1.s" -na
		;
connectAttr "murPort4_2014_tri:lambert16.msg" ":defaultShaderList1.s" -na;
connectAttr "murPort4_2014_tri:lambert17.msg" ":defaultShaderList1.s" -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert12.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert13.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert10.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert11.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert16.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert17.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert8.msg" ":defaultShaderList1.s" -na
		;
connectAttr "murPort4_2014_tri:mur22227_lambert9.msg" ":defaultShaderList1.s" -na
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert10.msg" ":defaultShaderList1.s" -na
		;
connectAttr "murPort4_2014_tri:mur22227_lambert11.msg" ":defaultShaderList1.s" -na
		;
connectAttr "murPort4_2014_tri:mur22227_lambert13.msg" ":defaultShaderList1.s" -na
		;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murPort4_2014_tri:lambert18.msg" ":defaultShaderList1.s" -na;
connectAttr "murPort4_2014_tri:lambert19.msg" ":defaultShaderList1.s" -na;
connectAttr "MurV2exportFromZbrush:defaultMat1.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "ReflectionMap.msg" ":defaultTextureList1.tx" -na;
connectAttr "file1.msg" ":defaultTextureList1.tx" -na;
connectAttr "file2.msg" ":defaultTextureList1.tx" -na;
connectAttr "Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_2_ReflectionMap.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "Mur5_optimized2014_2_file1.msg" ":defaultTextureList1.tx" -na;
connectAttr "Mur5_optimized2014_2_file2.msg" ":defaultTextureList1.tx" -na;
connectAttr "Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_4_ReflectionMap.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "Mur5_optimized2014_4_file1.msg" ":defaultTextureList1.tx" -na;
connectAttr "Mur5_optimized2014_4_file2.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert9_Flattened_Diffuse.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert9_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx" 
		-na;
connectAttr "lambert9_Flattened_Opacity.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert11_Flattened_Diffuse.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert11_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "lambert11_Flattened_Opacity.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert12_Flattened_Diffuse.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert12_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "lambert12_Flattened_Opacity.msg" ":defaultTextureList1.tx" -na;
connectAttr "murPort4_2014_tri:lambert12_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:ReflectionMap.msg" ":defaultTextureList1.tx" -na;
connectAttr "murPort4_2014_tri:lambert13_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:file1.msg" ":defaultTextureList1.tx" -na;
connectAttr "murPort4_2014_tri:file2.msg" ":defaultTextureList1.tx" -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert9_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert9_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert11_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert11_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert12_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_ReflectionMap1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_file1.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "murPort4_2014_tri:mur22227_file2.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1F.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:file3.msg" ":defaultTextureList1.tx" -na;
connectAttr "murPort4_2014_tri:file4.msg" ":defaultTextureList1.tx" -na;
connectAttr "murPort4_2014_tri:lambert18_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murPort4_2014_tri:file5.msg" ":defaultTextureList1.tx" -na;
connectAttr "MurV2exportFromZbrush:defaultMat1F.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "file3.msg" ":defaultTextureList1.tx" -na;
connectAttr "place2dTexture1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture3.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture4.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture5.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "Mur5_optimized2014_2_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_2_bump2d1.msg" ":defaultRenderUtilityList1.u" -na
		;
connectAttr "Mur5_optimized2014_2_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_2_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_2_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_2_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_2_bump2d2.msg" ":defaultRenderUtilityList1.u" -na
		;
connectAttr "Mur5_optimized2014_4_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_4_bump2d1.msg" ":defaultRenderUtilityList1.u" -na
		;
connectAttr "Mur5_optimized2014_4_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_4_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_4_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_4_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_4_bump2d2.msg" ":defaultRenderUtilityList1.u" -na
		;
connectAttr "place2dTexture6.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d3.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture7.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture8.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d4.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture9.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture10.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture11.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture12.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d5.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture13.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture14.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murPort4_2014_tri:place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:bump2d1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murPort4_2014_tri:place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:bump2d2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murPort4_2014_tri:place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_2_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:Mur5_optimized2014_4_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:bump2d3.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murPort4_2014_tri:place2dTexture7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture8.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:bump2d4.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murPort4_2014_tri:place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture11.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture12.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:bump2d5.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murPort4_2014_tri:place2dTexture13.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture14.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture15.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:bump2d6.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murPort4_2014_tri:place2dTexture16.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture17.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:bump2d7.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murPort4_2014_tri:place2dTexture18.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_mur22227_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture8.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture11.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture12.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture13.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture14.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture15.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture16.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture17.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_bump2d7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murBlock6_2014_place2dTexture18.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_bump2d3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture8.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_bump2d4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture11.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_bump2d5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture12.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture13.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_bump2d6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture14.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture15.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture16.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture17.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_bump2d7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture18.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:mur22227_place2dTexture19.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:murPort2:defaultMat1P2D.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture19.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture20.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:bump2d8.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murPort4_2014_tri:place2dTexture21.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:bump2d9.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murPort4_2014_tri:place2dTexture22.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:place2dTexture23.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murPort4_2014_tri:bump2d10.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "MurV2exportFromZbrush:defaultMat1P2D.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "place2dTexture15.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d6.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
dataStructure -fmt "raw" -as "name=externalContentTable:string=node:string=key:string=upath:uint32=upathcrc:string=rpath:string=roles";
applyMetadata -fmt "raw" -v "channel\nname externalContentTable\nstream\nname v1.0\nindexType numeric\nstructure externalContentTable\n0\n\"lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n1\n\"lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n2\n\"ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n3\n\"file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n4\n\"file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n5\n\"Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n6\n\"Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n7\n\"Mur5_optimized2014_2_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n8\n\"Mur5_optimized2014_2_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n9\n\"Mur5_optimized2014_2_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n10\n\"Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n11\n\"Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n12\n\"Mur5_optimized2014_4_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n13\n\"Mur5_optimized2014_4_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n14\n\"Mur5_optimized2014_4_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n15\n\"lambert9_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n16\n\"lambert9_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n17\n\"lambert9_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n18\n\"lambert11_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n19\n\"lambert11_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n20\n\"lambert11_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n21\n\"lambert12_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush1Text.png\" 2904893610 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush1Text.png\" \"sourceImages\"\n22\n\"lambert12_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush1Norm.png\" 675646610 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush1Norm.png\" \"sourceImages\"\n23\n\"lambert12_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n24\n\"murPort4_2014_tri:lambert12_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" 4288469390 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" \"sourceImages\"\n25\n\"murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" 2238725887 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" \"sourceImages\"\n26\n\"murPort4_2014_tri:ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n27\n\"murPort4_2014_tri:lambert13_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" 4288469390 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" \"sourceImages\"\n28\n\"murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" 2238725887 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" \"sourceImages\"\n29\n\"murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n30\n\"murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n31\n\"murPort4_2014_tri:mur22227_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n32\n\"murPort4_2014_tri:file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n33\n\"murPort4_2014_tri:file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n34\n\"murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n35\n\"murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n36\n\"murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n37\n\"murPort4_2014_tri:Mur5_optimized2014_2_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n38\n\"murPort4_2014_tri:Mur5_optimized2014_2_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n39\n\"murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n40\n\"murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n41\n\"murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n42\n\"murPort4_2014_tri:Mur5_optimized2014_4_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n43\n\"murPort4_2014_tri:Mur5_optimized2014_4_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n44\n\"murPort4_2014_tri:lambert9_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n45\n\"murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n46\n\"murPort4_2014_tri:lambert9_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n47\n\"murPort4_2014_tri:lambert11_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n48\n\"murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n49\n\"murPort4_2014_tri:lambert11_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n50\n\"murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n51\n\"murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n52\n\"murPort4_2014_tri:lambert12_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n53\n\"murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" 1636531969 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" \"sourceImages\"\n54\n\"murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal.png\" 3525560328 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal.png\" \"sourceImages\"\n55\n\"murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" 1636531969 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" \"sourceImages\"\n56\n\"murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal_u1_v1.png\" 2170994057 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal_u1_v1.png\" \"sourceImages\"\n57\n\"murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" 4288469390 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" \"sourceImages\"\n58\n\"murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" 2238725887 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" \"sourceImages\"\n59\n\"murPort4_2014_tri:murBlock6_2014_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n60\n\"murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" 4288469390 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" \"sourceImages\"\n61\n\"murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" 2238725887 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" \"sourceImages\"\n62\n\"murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n63\n\"murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n64\n\"murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n65\n\"murPort4_2014_tri:murBlock6_2014_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n66\n\"murPort4_2014_tri:murBlock6_2014_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n67\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n68\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n69\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n70\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n71\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n72\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n73\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n74\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n75\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n76\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n77\n\"murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n78\n\"murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n79\n\"murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n80\n\"murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n81\n\"murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n82\n\"murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n83\n\"murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n84\n\"murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n85\n\"murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n86\n\"murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" 1636531969 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" \"sourceImages\"\n87\n\"murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal.png\" 3525560328 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal.png\" \"sourceImages\"\n88\n\"murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" 1636531969 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" \"sourceImages\"\n89\n\"murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal_u1_v1.png\" 2170994057 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal_u1_v1.png\" \"sourceImages\"\n90\n\"murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n91\n\"murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n92\n\"murPort4_2014_tri:mur22227_ReflectionMap1\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n93\n\"murPort4_2014_tri:mur22227_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n94\n\"murPort4_2014_tri:mur22227_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n95\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n96\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n97\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n98\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n99\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n100\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n101\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n102\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n103\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n104\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n105\n\"murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n106\n\"murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n107\n\"murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n108\n\"murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n109\n\"murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n110\n\"murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n111\n\"murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n112\n\"murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n113\n\"murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n114\n\"murPort4_2014_tri:murPort2:defaultMat1F\" \"fileTextureName\" \"murPort2.bmp\" 1882535258 \"\" \"sourceImages\"\n115\n\"murPort4_2014_tri:file3\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort2_texture.png\" 3903194042 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort2_texture.png\" \"sourceImages\"\n116\n\"murPort4_2014_tri:file4\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort2_normal.png\" 396662271 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort2_normal.png\" \"sourceImages\"\n117\n\"murPort4_2014_tri:lambert18_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort5_texture.png\" 2513765858 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort5_texture.png\" \"sourceImages\"\n118\n\"murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort4_normal.png\" 4170788895 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort4_normal.png\" \"sourceImages\"\n119\n\"murPort4_2014_tri:file5\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort4_normal.png\" 4170788895 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort4_normal.png\" \"sourceImages\"\n120\n\"MurV2exportFromZbrush:defaultMat1F\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush3Text.png\" 2211643436 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush3Text.png\" \"sourceImages\"\n121\n\"file3\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush3Norm.png\" 112436244 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush3Norm.png\" \"sourceImages\"\nendStream\nendChannel\nendAssociations\n" 
		-scn;
// End of mur_V2_22229_2014.ma
