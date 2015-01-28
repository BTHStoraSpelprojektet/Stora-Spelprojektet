//Maya ASCII 2014 scene
//Name: murBlockMiniV2_2014_2.ma
//Last modified: Tue, Jan 20, 2015 10:26:58 AM
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
	setAttr ".t" -type "double3" -8.3677751650593777 10.603317909825059 -8.1998195218517971 ;
	setAttr ".r" -type "double3" -28.538352725322241 -1219.3999999997411 0 ;
createNode camera -s -n "perspShape" -p "persp";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".coi" 12.996256782733191;
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
	setAttr ".ow" 11.802389025074763;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
createNode transform -s -n "front";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 3.4499001472120896 4.5605081893882637 100.1 ;
createNode camera -s -n "frontShape" -p "front";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 100.1;
	setAttr ".ow" 16.245216301079012;
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
createNode transform -n "wallBlockMini";
createNode mesh -n "wallBlockMiniShape" -p "wallBlockMini";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.58236181927257902 0.49999997019767761 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 228 ".uvst[0].uvsp[0:227]" -type "float2" 0.014206904 0.0018474942
		 0.21465886 0.0018474942 0.21465886 0.68871927 0.014206904 0.68871927 0.22687373 0.69670862
		 0.0019920263 0.69670862 0.24632712 0.0098368209 0.44677907 0.0098368209 0.44677907
		 0.69670862 0.24632712 0.69670862 0.23411223 0.001847471 0.45899394 0.001847471 0.4782525
		 0.0018474942 0.67870444 0.0018474942 0.67870444 0.68871927 0.4782525 0.68871927 0.69091934
		 0.69670862 0.46603757 0.69670862 0.71017778 0.0018474942 0.91062975 0.0018474942
		 0.91062975 0.68871927 0.71017778 0.68871927 0.92284465 0.69670862 0.69796288 0.69670862
		 0.015824199 0.71119016 0.28667152 0.71119016 0.25197619 0.74588561 0.050519645 0.74588561
		 0.28667152 0.98203766 0.25197619 0.94734222 0.20841819 0.78944373 0.094077766 0.78944373
		 0.015824199 0.98203766 0.050519645 0.94734222 0.20841819 0.9037841 0.15323097 0.84463078
		 0.14926481 0.84463078 0.094077766 0.9037841 0.15323097 0.84859699 0.14926481 0.84859699
		 0.91326845 0.91140133 0.87948847 0.91140133 0.87652326 0.88678688 0.9162339 0.88678688
		 0.9086498 0.93093157 0.88410711 0.93093157 0.8521601 0.91140133 0.84439695 0.88678688
		 0.87550116 0.85950583 0.9172554 0.85950583 0.94059658 0.91140133 0.94836032 0.88678688
		 0.86425197 0.93093157 0.92850518 0.93093157 0.84172142 0.85950583 0.87652326 0.83222151
		 0.9162339 0.83222151 0.95103526 0.85950583 0.84439695 0.83222151 0.87948847 0.80760795
		 0.91326845 0.80760795 0.94836032 0.83222151 0.8521601 0.80760795 0.88410711 0.78807664
		 0.9086498 0.78807664 0.94059658 0.80760795 0.86425197 0.78807664 0.88992691 0.77553904
		 0.90282977 0.77553904 0.92850518 0.78807664 0.48414394 0.77553904 0.51627052 0.77553904
		 0.51627052 0.8001532 0.4785035 0.8001532 0.54839706 0.77553904 0.55403751 0.8001532
		 0.51627052 0.82743454 0.47656009 0.82743454 0.56825221 0.77553904 0.57737887 0.8001532
		 0.55598116 0.82743454 0.51627052 0.85471857 0.4785035 0.85471857 0.58052397 0.82743454
		 0.55403751 0.85471857 0.51627052 0.87933242 0.48414394 0.87933242 0.57737887 0.85471857
		 0.54839706 0.87933242 0.51627052 0.89886379 0.49292943 0.89886379 0.56825221 0.87933242
		 0.53961158 0.89886379 0.51627052 0.91140133 0.50399923 0.91140133 0.52854168 0.91140133
		 0.74254084 0.79506958 0.77632082 0.79506958 0.77928627 0.81968373 0.73957562 0.81968373
		 0.74715966 0.77553904 0.77170211 0.77553904 0.80364883 0.79506958 0.81141257 0.81968373
		 0.78030777 0.84696478 0.73855376 0.84696478 0.79155749 0.77553904 0.72730434 0.77553904
		 0.71521276 0.79506958 0.81408763 0.84696478 0.77928627 0.8742491 0.73957562 0.8742491
		 0.81141257 0.8742491 0.77632082 0.89886266 0.74254084 0.89886266 0.80364883 0.89886266
		 0.77170211 0.91839397 0.74715966 0.91839397 0.79155749 0.91839397 0.76588207 0.93093157
		 0.75297946 0.93093157 0.71521276 0.89886266 0.72730434 0.91839397 0.61574185 0.79506958
		 0.64786822 0.79506958 0.64786822 0.81968373 0.61010122 0.81968373 0.62452716 0.77553904
		 0.64786822 0.77553904 0.67999506 0.79506958 0.68563551 0.81968373 0.64786822 0.84696478
		 0.60815775 0.84696478 0.67120934 0.77553904 0.68757892 0.84696478 0.64786822 0.8742491
		 0.61010122 0.8742491 0.68563551 0.8742491 0.64786822 0.89886266 0.61574185 0.89886266
		 0.67999506 0.89886266 0.64786822 0.91839397 0.62452716 0.91839397 0.67120934 0.91839397
		 0.64786822 0.93093157 0.63559699 0.93093157 0.66013974 0.93093157 0.4489257 0.83664745
		 0.42907086 0.85107338 0.42325082 0.83316171 0.433689 0.82557756 0.4167994 0.81330633
		 0.41034818 0.83316171 0.43767652 0.81330633 0.39990923 0.82557756 0.433689 0.80103487
		 0.40452814 0.85107338 0.38467252 0.83664745 0.39592224 0.81330633 0.42325082 0.79345125
		 0.39990923 0.80103487 0.42907086 0.77553904 0.4489257 0.78996527 0.41034818 0.79345125
		 0.38467252 0.78996527 0.40452814 0.77553904 0.33494246 0.78432482 0.35703868 0.80766588
		 0.31241187 0.80766588 0.32285058 0.77553904 0.33494246 0.831007 0.32285058 0.83979249
		 0.91062975 0.10562479 0.014206903 0.10562479 0.21465886 0.10562479 0.4782525 0.10562479
		 0.71017778 0.10562476 0.24632712 0.59293139 0.44677907 0.59293139 0.67870444 0.10562476
		 0.71017778 0.1198272 0.24632712 0.57872897 0.44677907 0.57872897 0.67870444 0.1198272
		 0.91062975 0.11982721 0.014206903 0.11982721 0.21465886 0.11982721 0.4782525 0.11982721
		 0.014206903 0.10562479 0.21465886 0.10562479 0.21465886 0.11982721 0.014206903 0.11982721
		 0.4782525 0.10562479 0.67870444 0.10562476 0.67870444 0.1198272 0.4782525 0.11982721
		 0.71017778 0.10562476 0.91062975 0.10562479 0.91062975 0.11982721 0.71017778 0.1198272
		 0.24632712 0.57872897 0.44677907 0.57872897 0.44677907 0.59293139 0.24632712 0.59293139
		 0.33386576 0.86829215 0.35226142 0.86829215 0.33386576 0.88668793 0.36260903 0.88668793
		 0.33386576 0.89703554 0.35226142 0.89703554 0.33386576 0.91543132 0.33386576 0.94417471
		 0.39135253 0.89703554 0.4097482 0.89703554 0.39135253 0.91543132 0.4200958 0.91543132
		 0.39135253 0.95452231 0.4097482 0.95452231 0.39135253 0.97291809 0.4200958 0.97291809
		 0.6712085 0.41115329 0.49351513 0.41115329 0.48843554 0.40607369 0.67628813 0.40607369
		 0.49351513 0.58884668 0.48843557 0.59392625 0.6712085 0.58884668 0.67628813 0.59392625;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 121 ".vt[0:120]"  -1.42569721 0 1.81703842 1.42569721 0 1.81703842
		 -1.42569721 9.77063465 1.81703842 1.42569721 9.77063465 1.81703842 -1.42569721 9.77063465 -1.034355879
		 1.42569721 9.77063465 -1.034355879 -1.42569721 0 -1.034355879 1.42569721 0 -1.034355879
		 -1.59945226 9.88428116 1.99079359 1.59945226 9.88428116 1.99079359 1.59945226 9.88428116 -1.20811105
		 -1.59945226 9.88428116 -1.20811105 -1.18967462 10.023465157 1.58101583 1.18967462 10.023465157 1.58101583
		 1.18967462 10.023465157 -0.79833341 -1.18967462 10.023465157 -0.79833341 -0.023421848 10.75805759 0.41476303
		 0.023421848 10.75805759 0.41476303 0.023421848 10.75805759 0.36791947 -0.023421848 10.75805759 0.36791947
		 -0.6752218 10.23203659 1.06656301 0.6752218 10.23203659 1.06656301 0.6752218 10.23203659 -0.28388059
		 -0.6752218 10.23203659 -0.28388059 0.10146255 10.56523418 0.31325814 0.038755197 10.56523418 0.26769835
		 -0.038755216 10.56523418 0.26769835 -0.10146257 10.56523418 0.31325814 -0.031677604 10.75374126 0.38697436
		 -0.10146257 10.56523418 0.46069059 -0.03875516 10.56523418 0.50625044 0.038755231 10.56523418 0.50625044
		 0.10146255 10.56523418 0.46069059 0.12541434 10.56523418 0.38697436 0.13965005 10.64291096 0.28551179
		 0.053341955 10.64291096 0.22280574 -0.053341974 10.64291096 0.22280574 -0.13965008 10.64291096 0.28551179
		 -0.17261766 10.64291096 0.38697436 -0.13965005 10.64291096 0.48843691 -0.053341974 10.64291096 0.55114299
		 0.053341955 10.64291096 0.55114299 0.13965005 10.64291096 0.48843691 0.17261764 10.64291096 0.38697436
		 0.164169 10.70079994 0.26769835 0.062707163 10.70079994 0.19398206 -0.062707193 10.70079994 0.19398206
		 -0.16416903 10.70079994 0.26769835 -0.20292516 10.70079994 0.38697436 -0.164169 10.70079994 0.50625044
		 -0.062707171 10.70079994 0.57996666 0.062707171 10.70079994 0.57996666 0.16416898 10.70079994 0.50625044
		 0.20292513 10.70079994 0.38697436 0.17261764 10.7649622 0.26156014 0.065934055 10.7649622 0.1840492
		 -0.065934077 10.7649622 0.1840492 -0.17261766 10.7649622 0.26156014 -0.21336788 10.7649622 0.38697436
		 -0.17261766 10.7649622 0.51238853 -0.065934077 10.7649622 0.58989948 0.065934055 10.7649622 0.58989948
		 0.17261764 10.7649622 0.51238853 0.21336786 10.7649622 0.38697436 0.164169 10.82913017 0.26769835
		 0.062707163 10.82913017 0.19398206 -0.062707193 10.82913017 0.19398206 -0.16416903 10.82913017 0.26769835
		 -0.20292516 10.82913017 0.38697436 -0.164169 10.82913017 0.50625044 -0.062707171 10.82913017 0.57996666
		 0.062707171 10.82913017 0.57996666 0.16416898 10.82913017 0.50625044 0.20292513 10.82913017 0.38697436
		 0.13965005 10.88701916 0.28551179 0.053341955 10.88701916 0.22280574 -0.053341974 10.88701916 0.22280574
		 -0.13965008 10.88701916 0.28551179 -0.17261766 10.88701916 0.38697436 -0.13965005 10.88701916 0.48843691
		 -0.053341974 10.88701916 0.55114299 0.053341955 10.88701916 0.55114299 0.13965005 10.88701916 0.48843691
		 0.17261764 10.88701916 0.38697436 0.10146255 10.93295383 0.31325814 0.038755197 10.93295383 0.26769835
		 -0.038755216 10.93295383 0.26769835 -0.10146257 10.93295383 0.31325814 -0.12541434 10.93295383 0.38697436
		 -0.10146257 10.93295383 0.46069059 -0.03875516 10.93295383 0.50625044 0.038755231 10.93295383 0.50625044
		 0.10146255 10.93295383 0.46069059 0.12541434 10.93295383 0.38697436 0.053341955 10.96244049 0.34821919
		 0.020374821 10.96244049 0.32426727 -0.020374831 10.96244049 0.32426727 -0.053341974 10.96244049 0.34821919
		 -0.065934077 10.96244049 0.38697436 -0.053341974 10.96244049 0.4257296 -0.020374831 10.96244049 0.4496814
		 0.02037481 10.96244049 0.4496814 0.053341955 10.96244049 0.4257296 0.065934055 10.96244049 0.38697436
		 6.2771516e-010 10.97261524 0.38697436 -1.42569721 1.47621441 1.8170383 1.42569721 1.47621441 1.8170383
		 -1.42569721 1.47621393 -1.034355879 1.42569721 1.47621393 -1.034355879 -1.42569721 1.67824137 -1.034355879
		 1.42569721 1.67824137 -1.034355879 -1.42569709 1.67824161 1.8170383 1.42569709 1.67824161 1.8170383
		 1.50720799 1.4704392 1.89854908 -1.50720799 1.4704392 1.89854908 1.50720787 1.68401682 1.89854908
		 -1.50720787 1.68401682 1.89854908 1.50720799 1.47043872 -1.11586666 1.50720799 1.68401659 -1.11586666
		 -1.50720799 1.47043872 -1.11586666 -1.50720799 1.68401659 -1.11586666;
	setAttr -s 236 ".ed";
	setAttr ".ed[0:165]"  0 1 0 1 106 0 106 105 0 105 0 0 4 5 0 5 110 0 110 109 0
		 109 4 0 1 7 0 7 108 0 108 106 0 6 0 0 105 107 0 107 6 0 2 3 0 3 9 0 9 8 0 8 2 0 3 5 0
		 5 10 0 10 9 0 4 11 0 11 10 0 4 2 0 8 11 0 9 13 0 13 12 1 12 8 0 10 14 0 14 13 1 11 15 0
		 15 14 1 12 15 1 13 21 0 21 20 1 20 12 0 14 22 0 22 21 1 15 23 0 23 22 1 20 23 1 21 17 0
		 17 16 0 16 20 0 22 18 0 18 17 0 23 19 0 19 18 0 16 19 0 24 25 0 25 35 0 35 34 0 34 24 0
		 25 26 0 26 36 0 36 35 0 26 27 0 27 37 0 37 36 0 27 28 0 28 38 0 38 37 0 28 29 0 29 39 0
		 39 38 0 29 30 0 30 40 0 40 39 0 30 31 0 31 41 0 41 40 0 31 32 0 32 42 0 42 41 0 32 33 0
		 33 43 0 43 42 0 33 24 0 34 43 0 35 45 0 45 44 0 44 34 0 36 46 0 46 45 0 37 47 0 47 46 0
		 38 48 0 48 47 0 39 49 0 49 48 0 40 50 0 50 49 0 41 51 0 51 50 0 42 52 0 52 51 0 43 53 0
		 53 52 0 44 53 0 45 55 0 55 54 0 54 44 0 46 56 0 56 55 0 47 57 0 57 56 0 48 58 0 58 57 0
		 49 59 0 59 58 0 50 60 0 60 59 0 51 61 0 61 60 0 52 62 0 62 61 0 53 63 0 63 62 0 54 63 0
		 55 65 0 65 64 0 64 54 0 56 66 0 66 65 0 57 67 0 67 66 0 58 68 0 68 67 0 59 69 0 69 68 0
		 60 70 0 70 69 0 61 71 0 71 70 0 62 72 0 72 71 0 63 73 0 73 72 0 64 73 0 65 75 0 75 74 0
		 74 64 0 66 76 0 76 75 0 67 77 0 77 76 0 68 78 0 78 77 0 69 79 0 79 78 0 70 80 0 80 79 0
		 71 81 0 81 80 0 72 82 0 82 81 0 73 83 0 83 82 0 74 83 0 75 85 0 85 84 0 84 74 0 76 86 0
		 86 85 0 77 87 0 87 86 0;
	setAttr ".ed[166:235]" 78 88 0 88 87 0 79 89 0 89 88 0 80 90 0 90 89 0 81 91 0
		 91 90 0 82 92 0 92 91 0 83 93 0 93 92 0 84 93 0 85 95 0 95 94 0 94 84 0 86 96 0 96 95 0
		 87 97 0 97 96 0 88 98 0 98 97 0 89 99 0 99 98 0 90 100 0 100 99 0 91 101 0 101 100 0
		 92 102 0 102 101 0 93 103 0 103 102 0 94 103 0 95 104 0 104 94 0 96 104 0 97 104 0
		 98 104 0 99 104 0 100 104 0 101 104 0 102 104 0 103 104 0 114 113 0 113 115 0 115 116 0
		 116 114 0 107 108 0 7 6 0 113 117 0 117 118 0 118 115 0 119 114 0 116 120 0 120 119 0
		 120 118 0 117 119 0 111 112 0 112 3 0 2 111 0 112 110 0 109 111 0 106 113 0 114 105 0
		 111 116 0 115 112 0 108 117 0 118 110 0 119 107 0 109 120 0;
	setAttr -s 438 ".n";
	setAttr ".n[0:165]" -type "float3"  1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020;
	setAttr ".n[166:331]" -type "float3"  1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020;
	setAttr ".n[332:437]" -type "float3"  1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020
		 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020 1e+020;
	setAttr -s 116 -ch 454 ".fc[0:115]" -type "polyFaces" 
		f 4 0 1 2 3
		mu 0 4 0 1 174 173
		f 4 4 5 6 7
		mu 0 4 6 7 182 181
		f 4 8 9 10 -2
		mu 0 4 12 13 179 175
		f 4 11 -4 12 13
		mu 0 4 18 19 172 176
		f 4 14 15 16 17
		mu 0 4 3 2 4 5
		f 4 18 19 20 -16
		mu 0 4 15 14 16 17
		f 4 -5 21 22 -20
		mu 0 4 7 6 10 11
		f 4 23 -18 24 -22
		mu 0 4 21 20 22 23
		f 4 -17 25 26 27
		mu 0 4 24 25 26 27
		f 4 -21 28 29 -26
		mu 0 4 25 28 29 26
		f 4 -23 30 31 -29
		mu 0 4 28 32 33 29
		f 4 -25 -28 32 -31
		mu 0 4 32 24 27 33
		f 4 -27 33 34 35
		mu 0 4 27 26 30 31
		f 4 -30 36 37 -34
		mu 0 4 26 29 34 30
		f 4 -32 38 39 -37
		mu 0 4 29 33 37 34
		f 4 -33 -36 40 -39
		mu 0 4 33 27 31 37
		f 4 -35 41 42 43
		mu 0 4 31 30 35 36
		f 4 -38 44 45 -42
		mu 0 4 30 34 38 35
		f 4 -40 46 47 -45
		mu 0 4 34 37 39 38
		f 4 -41 -44 48 -47
		mu 0 4 37 31 36 39
		f 4 49 50 51 52
		mu 0 4 53 44 40 50
		f 4 53 54 55 -51
		mu 0 4 44 45 41 40
		f 4 56 57 58 -55
		mu 0 4 45 52 46 41
		f 4 59 60 61 -58
		mu 0 4 166 167 168 169
		f 4 62 63 64 -61
		mu 0 4 167 170 171 168
		f 4 65 66 67 -64
		mu 0 4 107 100 96 108
		f 4 68 69 70 -67
		mu 0 4 100 101 97 96
		f 4 71 72 73 -70
		mu 0 4 101 106 102 97
		f 4 74 75 76 -73
		mu 0 4 127 128 124 123
		f 4 77 -53 78 -76
		mu 0 4 128 133 129 124
		f 4 -52 79 80 81
		mu 0 4 50 40 43 51
		f 4 -56 82 83 -80
		mu 0 4 40 41 42 43
		f 4 -59 84 85 -83
		mu 0 4 41 46 47 42
		f 4 -62 86 87 -85
		mu 0 4 70 71 72 73
		f 4 -65 88 89 -87
		mu 0 4 71 74 75 72
		f 4 -68 90 91 -89
		mu 0 4 74 78 79 75
		f 4 -71 92 93 -91
		mu 0 4 96 97 98 99
		f 4 -74 94 95 -93
		mu 0 4 97 102 103 98
		f 4 -77 96 97 -95
		mu 0 4 123 124 125 126
		f 4 -79 -82 98 -97
		mu 0 4 124 129 130 125
		f 4 -81 99 100 101
		mu 0 4 51 43 49 57
		f 4 -84 102 103 -100
		mu 0 4 43 42 48 49
		f 4 -86 104 105 -103
		mu 0 4 42 47 54 48
		f 4 -88 106 107 -105
		mu 0 4 73 72 76 77
		f 4 -90 108 109 -107
		mu 0 4 72 75 80 76
		f 4 -92 110 111 -109
		mu 0 4 75 79 83 80
		f 4 -94 112 113 -111
		mu 0 4 99 98 104 105
		f 4 -96 114 115 -113
		mu 0 4 98 103 109 104
		f 4 -98 116 117 -115
		mu 0 4 126 125 131 132
		f 4 -99 -102 118 -117
		mu 0 4 125 130 134 131
		f 4 -101 119 120 121
		mu 0 4 57 49 56 61
		f 4 -104 122 123 -120
		mu 0 4 49 48 55 56
		f 4 -106 124 125 -123
		mu 0 4 48 54 58 55
		f 4 -108 126 127 -125
		mu 0 4 77 76 81 82
		f 4 -110 128 129 -127
		mu 0 4 76 80 84 81
		f 4 -112 130 131 -129
		mu 0 4 80 83 87 84
		f 4 -114 132 133 -131
		mu 0 4 105 104 110 111
		f 4 -116 134 135 -133
		mu 0 4 104 109 112 110
		f 4 -118 136 137 -135
		mu 0 4 132 131 135 136
		f 4 -119 -122 138 -137
		mu 0 4 131 134 137 135
		f 4 -121 139 140 141
		mu 0 4 61 56 60 65
		f 4 -124 142 143 -140
		mu 0 4 56 55 59 60
		f 4 -126 144 145 -143
		mu 0 4 55 58 62 59
		f 4 -128 146 147 -145
		mu 0 4 82 81 85 86
		f 4 -130 148 149 -147
		mu 0 4 81 84 88 85
		f 4 -132 150 151 -149
		mu 0 4 84 87 91 88
		f 4 -134 152 153 -151
		mu 0 4 111 110 113 114
		f 4 -136 154 155 -153
		mu 0 4 110 112 115 113
		f 4 -138 156 157 -155
		mu 0 4 136 135 138 139
		f 4 -139 -142 158 -157
		mu 0 4 135 137 140 138
		f 4 -141 159 160 161
		mu 0 4 65 60 64 69
		f 4 -144 162 163 -160
		mu 0 4 60 59 63 64
		f 4 -146 164 165 -163
		mu 0 4 59 62 66 63
		f 4 -148 166 167 -165
		mu 0 4 86 85 89 90
		f 4 -150 168 169 -167
		mu 0 4 85 88 92 89
		f 4 -152 170 171 -169
		mu 0 4 121 114 117 122
		f 4 -154 172 173 -171
		mu 0 4 114 113 116 117
		f 4 -156 174 175 -173
		mu 0 4 113 115 118 116
		f 4 -158 176 177 -175
		mu 0 4 139 138 141 142
		f 4 -159 -162 178 -177
		mu 0 4 138 140 143 141
		f 4 -161 179 180 181
		mu 0 4 147 148 149 150
		f 4 -164 182 183 -180
		mu 0 4 64 63 67 68
		f 4 -166 184 185 -183
		mu 0 4 156 157 154 152
		f 4 -168 186 187 -185
		mu 0 4 90 89 93 94
		f 4 -170 188 189 -187
		mu 0 4 89 92 95 93
		f 4 -172 190 191 -189
		mu 0 4 164 165 163 160
		f 4 -174 192 193 -191
		mu 0 4 117 116 119 120
		f 4 -176 194 195 -193
		mu 0 4 161 162 155 159
		f 4 -178 196 197 -195
		mu 0 4 142 141 144 145
		f 4 -179 -182 198 -197
		mu 0 4 141 143 146 144
		f 3 -181 199 200
		mu 0 3 150 149 151
		f 3 -184 201 -200
		mu 0 3 149 152 151
		f 3 -186 202 -202
		mu 0 3 152 154 151
		f 3 -188 203 -203
		mu 0 3 154 158 151
		f 3 -190 204 -204
		mu 0 3 158 160 151
		f 3 -192 205 -205
		mu 0 3 160 163 151
		f 3 -194 206 -206
		mu 0 3 163 159 151
		f 3 -196 207 -207
		mu 0 3 159 155 151
		f 3 -198 208 -208
		mu 0 3 155 153 151
		f 3 -199 -201 -209
		mu 0 3 153 150 151
		f 4 209 210 211 212
		mu 0 4 188 189 190 191
		f 4 213 -10 214 -14
		mu 0 4 177 178 8 9
		f 4 215 216 217 -211
		mu 0 4 192 193 194 195
		f 4 218 -213 219 220
		mu 0 4 196 197 198 199
		f 4 221 -217 222 -221
		mu 0 4 200 201 202 203
		f 4 223 224 -15 225
		mu 0 4 185 186 2 3
		f 4 226 -6 -19 -225
		mu 0 4 187 183 14 15
		f 4 227 -226 -24 -8
		mu 0 4 180 184 20 21
		f 4 -3 228 -210 229
		mu 0 4 204 205 206 207
		f 4 -224 230 -212 231
		mu 0 4 220 221 222 223
		f 4 -11 232 -216 -229
		mu 0 4 208 209 210 211
		f 4 -227 -232 -218 233
		mu 0 4 226 220 223 227
		f 4 -13 -230 -219 234
		mu 0 4 212 213 214 215
		f 4 -228 235 -220 -231
		mu 0 4 221 224 225 222
		f 4 -7 -234 -222 -236
		mu 0 4 224 226 227 225
		f 4 -214 -235 -223 -233
		mu 0 4 216 217 218 219;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
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
	addAttr -ci true -sn "miSamplesQualityR" -ln "miSamplesQualityR" -dv 0.25 -min 0.01 
		-max 9999999.9000000004 -smn 0.1 -smx 2 -at "double";
	addAttr -ci true -sn "miSamplesQualityG" -ln "miSamplesQualityG" -dv 0.25 -min 0.01 
		-max 9999999.9000000004 -smn 0.1 -smx 2 -at "double";
	addAttr -ci true -sn "miSamplesQualityB" -ln "miSamplesQualityB" -dv 0.25 -min 0.01 
		-max 9999999.9000000004 -smn 0.1 -smx 2 -at "double";
	addAttr -ci true -sn "miSamplesQualityA" -ln "miSamplesQualityA" -dv 0.25 -min 0.01 
		-max 9999999.9000000004 -smn 0.1 -smx 2 -at "double";
	addAttr -ci true -sn "miSamplesMin" -ln "miSamplesMin" -dv 1 -min 0.1 -at "double";
	addAttr -ci true -sn "miSamplesMax" -ln "miSamplesMax" -dv 100 -min 0.1 -at "double";
	addAttr -ci true -sn "miSamplesErrorCutoffR" -ln "miSamplesErrorCutoffR" -min 0 
		-max 1 -at "double";
	addAttr -ci true -sn "miSamplesErrorCutoffG" -ln "miSamplesErrorCutoffG" -min 0 
		-max 1 -at "double";
	addAttr -ci true -sn "miSamplesErrorCutoffB" -ln "miSamplesErrorCutoffB" -min 0 
		-max 1 -at "double";
	addAttr -ci true -sn "miSamplesErrorCutoffA" -ln "miSamplesErrorCutoffA" -min 0 
		-max 1 -at "double";
	addAttr -ci true -sn "miSamplesPerObject" -ln "miSamplesPerObject" -min 0 -max 1 
		-at "bool";
	addAttr -ci true -sn "miRastShadingSamples" -ln "miRastShadingSamples" -dv 1 -min 
		0.25 -at "double";
	addAttr -ci true -sn "miRastSamples" -ln "miRastSamples" -dv 3 -min 1 -at "long";
	addAttr -ci true -sn "miContrastAsColor" -ln "miContrastAsColor" -min 0 -max 1 -at "bool";
	addAttr -ci true -sn "miProgMaxTime" -ln "miProgMaxTime" -min 0 -at "long";
	addAttr -ci true -sn "miProgSubsampleSize" -ln "miProgSubsampleSize" -dv 4 -min 
		1 -at "long";
	addAttr -ci true -sn "miTraceCameraMotionVectors" -ln "miTraceCameraMotionVectors" 
		-min 0 -max 1 -at "bool";
	addAttr -ci true -sn "miTraceCameraClip" -ln "miTraceCameraClip" -min 0 -max 1 -at "bool";
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
createNode lightLinker -s -n "lightLinker1";
	setAttr -s 113 ".lnk";
	setAttr -s 113 ".slnk";
createNode displayLayerManager -n "layerManager";
createNode displayLayer -n "defaultLayer";
createNode renderLayerManager -n "renderLayerManager";
createNode renderLayer -n "defaultRenderLayer";
	setAttr ".g" yes;
createNode phong -n "lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "wallBlockSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo1";
createNode file -n "lambert12_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png";
createNode place2dTexture -n "place2dTexture1";
createNode bump2d -n "bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "lambert12_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "place2dTexture2";
createNode file -n "ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "place2dTexture3";
createNode script -n "uiConfigurationScriptNode";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"top\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n"
		+ "                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n"
		+ "                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n"
		+ "                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n"
		+ "            -rendererName \"base_OpenGL_Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 0\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n"
		+ "            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"side\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n"
		+ "                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n"
		+ "                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n"
		+ "                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n"
		+ "            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 0\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n"
		+ "            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n"
		+ "\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"front\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n"
		+ "                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n"
		+ "                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n"
		+ "                -shadows 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n"
		+ "            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 0\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n"
		+ "            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n"
		+ "        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n"
		+ "                -displayTextures 1\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n"
		+ "                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n"
		+ "                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n"
		+ "            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 1\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n"
		+ "            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n"
		+ "            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `outlinerPanel -unParent -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            outlinerEditor -e \n                -showShapes 0\n                -showReferenceNodes 1\n                -showReferenceMembers 1\n                -showAttributes 0\n                -showConnected 0\n                -showAnimCurvesOnly 0\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n"
		+ "                -autoExpand 0\n                -showDagOnly 1\n                -showAssets 1\n                -showContainedOnly 1\n                -showPublishedAsConnected 0\n                -showContainerContents 1\n                -ignoreDagHierarchy 0\n                -expandConnections 0\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 0\n                -highlightActive 1\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"defaultSetFilter\" \n                -showSetMembers 1\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n"
		+ "                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showReferenceNodes 1\n            -showReferenceMembers 1\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n"
		+ "            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n"
		+ "            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\tif ($useSceneConfig) {\n\t\toutlinerPanel -e -to $panelName;\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"graphEditor\" -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n"
		+ "                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n"
		+ "                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                -mapMotionTrails 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showResults \"off\" \n                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n"
		+ "                -stackedCurves 0\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -displayNormalized 0\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -classicMode 1\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n"
		+ "                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n"
		+ "                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                -mapMotionTrails 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showResults \"off\" \n                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -stackedCurves 0\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n"
		+ "                -displayNormalized 0\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -classicMode 1\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dopeSheetPanel\" (localizedPanelLabel(\"Dope Sheet\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dopeSheetPanel\" -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n"
		+ "                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n"
		+ "                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n"
		+ "                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n"
		+ "                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"clipEditorPanel\" (localizedPanelLabel(\"Trax Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"clipEditorPanel\" -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n"
		+ "                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -manageSequencer 0 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -manageSequencer 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"sequenceEditorPanel\" (localizedPanelLabel(\"Camera Sequencer\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"sequenceEditorPanel\" -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels `;\n"
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
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"Stereo\" (localizedPanelLabel(\"Stereo\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"Stereo\" -l (localizedPanelLabel(\"Stereo\")) -mbv $menusOkayInPanels `;\nstring $editorName = ($panelName+\"Editor\");\n            stereoCameraView -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n"
		+ "                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 4 4 \n                -bumpResolution 4 4 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n"
		+ "                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n"
		+ "                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -displayMode \"centerEye\" \n                -viewColor 0 0 0 1 \n                -useCustomBackground 1\n                $editorName;\n            stereoCameraView -e -viewSelected 0 $editorName;\n            stereoCameraView -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Stereo\")) -mbv $menusOkayInPanels  $panelName;\nstring $editorName = ($panelName+\"Editor\");\n            stereoCameraView -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n"
		+ "                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 4 4 \n"
		+ "                -bumpResolution 4 4 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n"
		+ "                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -displayMode \"centerEye\" \n                -viewColor 0 0 0 1 \n                -useCustomBackground 1\n                $editorName;\n            stereoCameraView -e -viewSelected 0 $editorName;\n            stereoCameraView -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n"
		+ "        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n\t\t\t\t-defaultImage \"\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"vertical2\\\" -ps 1 50 100 -ps 2 50 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Persp View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"UV Texture Editor\")) \n\t\t\t\t\t\"scriptedPanel\"\n\t\t\t\t\t\"$panelName = `scriptedPanel -unParent  -type \\\"polyTexturePlacementPanel\\\" -l (localizedPanelLabel(\\\"UV Texture Editor\\\")) -mbv $menusOkayInPanels `\"\n\t\t\t\t\t\"scriptedPanel -edit -l (localizedPanelLabel(\\\"UV Texture Editor\\\")) -mbv $menusOkayInPanels  $panelName\"\n\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        setFocus `paneLayout -q -p1 $gMainPane`;\n        sceneUIReplacement -deleteRemaining;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 12 -divisions 5 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 120 -ast 1 -aet 200 ";
	setAttr ".st" 6;
createNode phong -n "lambert13";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "wallBlockSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo2";
createNode file -n "lambert13_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png";
createNode place2dTexture -n "place2dTexture4";
createNode bump2d -n "bump2d2";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "lambert13_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "place2dTexture5";
createNode phong -n "lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur22227_materialInfo1";
createNode file -n "lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "mur22227_place2dTexture1";
createNode bump2d -n "mur22227_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "mur22227_place2dTexture2";
createNode file -n "mur22227_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur22227_place2dTexture3";
createNode lambert -n "lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur22227_materialInfo2";
createNode file -n "file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur22227_place2dTexture4";
createNode file -n "file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur22227_place2dTexture5";
createNode bump2d -n "mur22227_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
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
createNode phong -n "mur22227_lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "wallSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo5";
createNode file -n "mur22227_lambert12_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "place2dTexture12";
createNode bump2d -n "bump2d5";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "lambert12_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "place2dTexture13";
createNode file -n "lambert12_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "place2dTexture14";
createNode phong -n "lambert16";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "wallBlockSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo6";
createNode file -n "lambert16_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png";
createNode place2dTexture -n "place2dTexture15";
createNode bump2d -n "bump2d6";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 1.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "lambert16_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal.png";
createNode place2dTexture -n "place2dTexture16";
createNode phong -n "lambert17";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "wallBlockSG3";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo7";
createNode file -n "lambert17_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlockMini/murBlockTexture1024x1024_u1_v1.png";
createNode place2dTexture -n "place2dTexture17";
createNode bump2d -n "bump2d7";
	setAttr ".vc1" -type "float3" 0 2.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "lambert17_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal_u1_v1.png";
createNode place2dTexture -n "place2dTexture18";
createNode shadingEngine -n "murBlockMini5_2014_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini5_2014_materialInfo1";
createNode file -n "murBlockMini5_2014_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture1";
createNode bump2d -n "murBlockMini5_2014_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture2";
createNode file -n "murBlockMini5_2014_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture3";
createNode shadingEngine -n "murBlockMini5_2014_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini5_2014_materialInfo2";
createNode file -n "murBlockMini5_2014_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture4";
createNode file -n "murBlockMini5_2014_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2_normal.png";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture5";
createNode bump2d -n "murBlockMini5_2014_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode shadingEngine -n "Mur5_optimized2014_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_materialInfo1";
createNode file -n "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_place2dTexture1";
createNode bump2d -n "Mur5_optimized2014_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_place2dTexture2";
createNode file -n "Mur5_optimized2014_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "Mur5_optimized2014_place2dTexture3";
createNode shadingEngine -n "Mur5_optimized2014_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_materialInfo2";
createNode file -n "Mur5_optimized2014_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "Mur5_optimized2014_place2dTexture4";
createNode file -n "Mur5_optimized2014_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2_normal.png";
createNode place2dTexture -n "Mur5_optimized2014_place2dTexture5";
createNode bump2d -n "Mur5_optimized2014_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode shadingEngine -n "Mur5_optimized2014_polySurface33SG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_materialInfo3";
createNode file -n "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_place2dTexture6";
createNode bump2d -n "Mur5_optimized2014_bump2d3";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_place2dTexture7";
createNode file -n "Mur5_optimized2014_ReflectionMap1";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "Mur5_optimized2014_place2dTexture8";
createNode shadingEngine -n "Mur5_optimized2014_lambert9SG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_materialInfo4";
createNode file -n "Mur5_optimized2014_file3";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "Mur5_optimized2014_place2dTexture9";
createNode file -n "Mur5_optimized2014_file4";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2_normal.png";
createNode place2dTexture -n "Mur5_optimized2014_place2dTexture10";
createNode bump2d -n "Mur5_optimized2014_bump2d4";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode shadingEngine -n "pasted__Mur5_optimized2014_lambert9SG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "pasted__Mur5_optimized2014_materialInfo4";
createNode file -n "pasted__Mur5_optimized2014_file3";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "pasted__Mur5_optimized2014_place2dTexture9";
createNode bump2d -n "pasted__Mur5_optimized2014_bump2d4";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "pasted__Mur5_optimized2014_file4";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2_normal.png";
createNode place2dTexture -n "pasted__Mur5_optimized2014_place2dTexture10";
createNode shadingEngine -n "polySurface34SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini5_2014_materialInfo3";
createNode file -n "lambert1_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlockMini/murBlockTexture1024x1024.png";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture6";
createNode shadingEngine -n "polySurface34SG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini5_2014_materialInfo4";
createNode bump2d -n "murBlockMini5_2014_bump2d3";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "lambert1_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlockMini/mur1024x1024Normal.png";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture7";
createNode phong -n "murBlockMini5_2014_lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "polySurface34SG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini5_2014_materialInfo5";
createNode bump2d -n "murBlockMini5_2014_bump2d4";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 3.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murBlockMini5_2014_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "Mur5_optimized2014_5_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_5_materialInfo1";
createNode file -n "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture1";
createNode bump2d -n "Mur5_optimized2014_5_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture2";
createNode file -n "Mur5_optimized2014_5_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture3";
createNode lambert -n "murBlockMini5_2014_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "Mur5_optimized2014_5_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_5_materialInfo2";
createNode file -n "Mur5_optimized2014_5_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture4";
createNode file -n "Mur5_optimized2014_5_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture5";
createNode bump2d -n "Mur5_optimized2014_5_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murBlockMini5_2014_Mur5_optimized2014_2_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murBlockMini5_2014_Mur5_optimized2014_2_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini5_2014_Mur5_optimized2014_2_materialInfo1";
createNode file -n "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture1";
createNode bump2d -n "murBlockMini5_2014_Mur5_optimized2014_2_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture2";
createNode file -n "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture3";
createNode lambert -n "murBlockMini5_2014_Mur5_optimized2014_2_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murBlockMini5_2014_Mur5_optimized2014_2_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini5_2014_Mur5_optimized2014_2_materialInfo2";
createNode file -n "murBlockMini5_2014_Mur5_optimized2014_2_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4";
createNode file -n "murBlockMini5_2014_Mur5_optimized2014_2_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5";
createNode bump2d -n "murBlockMini5_2014_Mur5_optimized2014_2_bump2d2";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murBlockMini5_2014_Mur5_optimized2014_4_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murBlockMini5_2014_Mur5_optimized2014_4_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini5_2014_Mur5_optimized2014_4_materialInfo1";
createNode file -n "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture1";
createNode bump2d -n "murBlockMini5_2014_Mur5_optimized2014_4_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture2";
createNode file -n "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture3";
createNode lambert -n "murBlockMini5_2014_Mur5_optimized2014_4_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murBlockMini5_2014_Mur5_optimized2014_4_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini5_2014_Mur5_optimized2014_4_materialInfo2";
createNode file -n "murBlockMini5_2014_Mur5_optimized2014_4_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4";
createNode file -n "murBlockMini5_2014_Mur5_optimized2014_4_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5";
createNode bump2d -n "murBlockMini5_2014_Mur5_optimized2014_4_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murBlockMini5_2014_lambert10";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murBlockMini5_2014_wallSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_5_materialInfo3";
createNode file -n "murBlockMini5_2014_lambert9_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture6";
createNode bump2d -n "Mur5_optimized2014_5_bump2d3";
createNode file -n "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture7";
createNode file -n "murBlockMini5_2014_lambert9_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture8";
createNode phong -n "murBlockMini5_2014_lambert11";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murBlockMini5_2014_wallSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_5_materialInfo4";
createNode bump2d -n "Mur5_optimized2014_5_bump2d4";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murBlockMini5_2014_lambert11_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur512x512.png";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture9";
createNode file -n "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture10";
createNode file -n "murBlockMini5_2014_lambert11_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture11";
createNode shadingEngine -n "murBlockMini1_2014_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_materialInfo1";
createNode file -n "murBlockMini1_2014_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini1_2014_place2dTexture1";
createNode bump2d -n "murBlockMini1_2014_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini1_2014_place2dTexture2";
createNode file -n "murBlockMini1_2014_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murBlockMini1_2014_place2dTexture3";
createNode shadingEngine -n "murBlockMini1_2014_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_materialInfo2";
createNode file -n "murBlockMini1_2014_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini1_2014_place2dTexture4";
createNode file -n "murBlockMini1_2014_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2_normal.png";
createNode place2dTexture -n "murBlockMini1_2014_place2dTexture5";
createNode bump2d -n "murBlockMini1_2014_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode shadingEngine -n "murBlockMini1_2014_Mur5_optimized2014_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_Mur5_optimized2014_materialInfo1";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_place2dTexture1";
createNode bump2d -n "murBlockMini1_2014_Mur5_optimized2014_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_place2dTexture2";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_place2dTexture3";
createNode shadingEngine -n "murBlockMini1_2014_Mur5_optimized2014_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_Mur5_optimized2014_materialInfo2";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2_normal.png";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5";
createNode bump2d -n "murBlockMini1_2014_Mur5_optimized2014_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode shadingEngine -n "murBlockMini1_2014_Mur5_optimized2014_polySurface33SG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_Mur5_optimized2014_materialInfo3";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_place2dTexture6";
createNode bump2d -n "murBlockMini1_2014_Mur5_optimized2014_bump2d3";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_place2dTexture7";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap1";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_place2dTexture8";
createNode shadingEngine -n "murBlockMini1_2014_Mur5_optimized2014_lambert9SG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_Mur5_optimized2014_materialInfo4";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_file3";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_file4";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2_normal.png";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10";
createNode bump2d -n "murBlockMini1_2014_Mur5_optimized2014_bump2d4";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode shadingEngine -n "murBlockMini1_2014_pasted__Mur5_optimized2014_lambert9SG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_pasted__Mur5_optimized2014_materialInfo4";
createNode file -n "murBlockMini1_2014_pasted__Mur5_optimized2014_file3";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9";
createNode bump2d -n "murBlockMini1_2014_pasted__Mur5_optimized2014_bump2d4";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murBlockMini1_2014_pasted__Mur5_optimized2014_file4";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2_normal.png";
createNode place2dTexture -n "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10";
createNode shadingEngine -n "murBlockMini1_2014_polySurface34SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_materialInfo3";
createNode file -n "murBlockMini1_2014_lambert1_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png";
createNode place2dTexture -n "murBlockMini1_2014_place2dTexture6";
createNode shadingEngine -n "murBlockMini1_2014_polySurface34SG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_materialInfo4";
createNode bump2d -n "murBlockMini1_2014_bump2d3";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "murBlockMini1_2014_place2dTexture7";
createNode phong -n "murBlockMini1_2014_lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murBlockMini1_2014_polySurface34SG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_materialInfo5";
createNode bump2d -n "murBlockMini1_2014_bump2d4";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murBlockMini1_2014_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murBlockMini1_2014_Mur5_optimized2014_5_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo1";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture1";
createNode bump2d -n "murBlockMini1_2014_Mur5_optimized2014_5_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture2";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture3";
createNode lambert -n "murBlockMini1_2014_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murBlockMini1_2014_Mur5_optimized2014_5_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo2";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_5_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_5_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5";
createNode bump2d -n "murBlockMini1_2014_Mur5_optimized2014_5_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murBlockMini1_2014_Mur5_optimized2014_2_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murBlockMini1_2014_Mur5_optimized2014_2_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_Mur5_optimized2014_2_materialInfo1";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture1";
createNode bump2d -n "murBlockMini1_2014_Mur5_optimized2014_2_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture2";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture3";
createNode lambert -n "murBlockMini1_2014_Mur5_optimized2014_2_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murBlockMini1_2014_Mur5_optimized2014_2_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_Mur5_optimized2014_2_materialInfo2";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_2_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_2_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5";
createNode bump2d -n "murBlockMini1_2014_Mur5_optimized2014_2_bump2d2";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murBlockMini1_2014_Mur5_optimized2014_4_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murBlockMini1_2014_Mur5_optimized2014_4_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_Mur5_optimized2014_4_materialInfo1";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture1";
createNode bump2d -n "murBlockMini1_2014_Mur5_optimized2014_4_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture2";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture3";
createNode lambert -n "murBlockMini1_2014_Mur5_optimized2014_4_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "murBlockMini1_2014_Mur5_optimized2014_4_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_Mur5_optimized2014_4_materialInfo2";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_4_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4";
createNode file -n "murBlockMini1_2014_Mur5_optimized2014_4_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5";
createNode bump2d -n "murBlockMini1_2014_Mur5_optimized2014_4_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "murBlockMini1_2014_lambert10";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murBlockMini1_2014_wallSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo3";
createNode file -n "murBlockMini1_2014_lambert9_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture6";
createNode bump2d -n "murBlockMini1_2014_Mur5_optimized2014_5_bump2d3";
createNode file -n "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture7";
createNode file -n "murBlockMini1_2014_lambert9_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini1_2014_place2dTexture8";
createNode phong -n "murBlockMini1_2014_lambert11";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "murBlockMini1_2014_wallSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo4";
createNode bump2d -n "murBlockMini1_2014_Mur5_optimized2014_5_bump2d4";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "murBlockMini1_2014_lambert11_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur512x512.png";
createNode place2dTexture -n "murBlockMini1_2014_place2dTexture9";
createNode file -n "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "murBlockMini1_2014_place2dTexture10";
createNode file -n "murBlockMini1_2014_lambert11_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "murBlockMini1_2014_place2dTexture11";
createNode phong -n "Mur5_optimized2014_5_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "Mur5_optimized2014_5_polySurface33SG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_5_materialInfo5";
createNode file -n "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture8";
createNode bump2d -n "Mur5_optimized2014_5_bump2d5";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture9";
createNode file -n "Mur5_optimized2014_5_ReflectionMap1";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture10";
createNode lambert -n "Mur5_optimized2014_5_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "Mur5_optimized2014_5_lambert9SG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_5_materialInfo6";
createNode file -n "Mur5_optimized2014_5_file3";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture11";
createNode file -n "Mur5_optimized2014_5_file4";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture12";
createNode bump2d -n "Mur5_optimized2014_5_bump2d6";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "Mur5_optimized2014_5_Mur5_optimized2014_2_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_5_Mur5_optimized2014_2_materialInfo1";
createNode file -n "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture1";
createNode bump2d -n "Mur5_optimized2014_5_Mur5_optimized2014_2_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture2";
createNode file -n "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture3";
createNode lambert -n "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_5_Mur5_optimized2014_2_materialInfo2";
createNode file -n "Mur5_optimized2014_5_Mur5_optimized2014_2_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4";
createNode file -n "Mur5_optimized2014_5_Mur5_optimized2014_2_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5";
createNode bump2d -n "Mur5_optimized2014_5_Mur5_optimized2014_2_bump2d2";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "Mur5_optimized2014_5_Mur5_optimized2014_4_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_5_Mur5_optimized2014_4_materialInfo1";
createNode file -n "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture1";
createNode bump2d -n "Mur5_optimized2014_5_Mur5_optimized2014_4_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture2";
createNode file -n "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture3";
createNode lambert -n "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_5_Mur5_optimized2014_4_materialInfo2";
createNode file -n "Mur5_optimized2014_5_Mur5_optimized2014_4_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4";
createNode file -n "Mur5_optimized2014_5_Mur5_optimized2014_4_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5";
createNode bump2d -n "Mur5_optimized2014_5_Mur5_optimized2014_4_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "Mur5_optimized2014_5_lambert10";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "Mur5_optimized2014_5_wallSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_5_materialInfo7";
createNode file -n "Mur5_optimized2014_5_lambert9_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture13";
createNode bump2d -n "Mur5_optimized2014_5_bump2d7";
createNode file -n "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture14";
createNode file -n "Mur5_optimized2014_5_lambert9_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture15";
createNode phong -n "Mur5_optimized2014_5_lambert11";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "Mur5_optimized2014_5_wallSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "Mur5_optimized2014_5_materialInfo8";
createNode bump2d -n "Mur5_optimized2014_5_bump2d8";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "Mur5_optimized2014_5_lambert11_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur512x512.png";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture16";
createNode file -n "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture17";
createNode file -n "Mur5_optimized2014_5_lambert11_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "Mur5_optimized2014_5_place2dTexture18";
createNode file -n "murBlockMini5_2014_lambert12_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlockMini/murBlockTexture1024x1024.png";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture12";
createNode file -n "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlockMini/mur1024x1024Normal.png";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture13";
createNode phong -n "lambert14";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "wallBlockMiniSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "murBlockMini5_2014_materialInfo6";
createNode file -n "lambert14_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlockMini/murBlockTexture1024x1024.png";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture14";
createNode bump2d -n "murBlockMini5_2014_bump2d5";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "lambert14_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlockMini/mur1024x1024Normal.png";
createNode place2dTexture -n "murBlockMini5_2014_place2dTexture15";
createNode file -n "lambert14_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlockMini/murBlockTexture1024x1024_u1_v1.png";
createNode place2dTexture -n "place2dTexture19";
createNode file -n "lambert14_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlockMini/mur1024x1024Normal_u1_v1.png";
createNode place2dTexture -n "place2dTexture20";
createNode phong -n "lambert15";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "wallBlockMiniSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo8";
createNode file -n "lambert15_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlockMini/murBlockTexture1024x1024_u1_v1.png";
createNode place2dTexture -n "place2dTexture21";
createNode bump2d -n "bump2d8";
	setAttr ".vc1" -type "float3" 0 3.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "lambert15_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlockMini/mur1024x1024Normal_u1_v1.png";
createNode place2dTexture -n "place2dTexture22";
createNode file -n "lambert15_Flattened_BumpFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlockMini/murBlockNormal1024x1024_u1_v1.tif";
createNode place2dTexture -n "place2dTexture23";
createNode file -n "lambert17_Flattened_BumpFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlockMini/murBlockNormal1024x1024_u1_v1.tif";
createNode place2dTexture -n "place2dTexture24";
createNode lambert -n "lambert18";
createNode shadingEngine -n "lambert18SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo9";
createNode file -n "file3";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlockMini/murBlockMini6-files/lambert15_Flattened_Diffuse_u1_v1_u1_v1.png";
createNode place2dTexture -n "place2dTexture25";
createNode file -n "file4";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlockMini/murBlockMini6-files/lambert15_Flattened_Diffuse_u1_v1 copy_u1_v1.png";
createNode place2dTexture -n "place2dTexture26";
createNode bump2d -n "bump2d9";
	setAttr ".vc1" -type "float3" 0 1.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "lambert19";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "wallBlockMiniSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo10";
createNode file -n "lambert18_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlockMini/murBlockMini6-files/lambert15_Flattened_Diffuse_u1_v1_u1_v1.png";
createNode place2dTexture -n "place2dTexture27";
createNode bump2d -n "bump2d10";
createNode file -n "lambert18_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlockMini/murBlockMini6-files/lambert15_Flattened_Diffuse_u1_v1 copy_u1_v1.png";
createNode place2dTexture -n "place2dTexture28";
createNode phong -n "lambert20";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "wallBlockMiniSG3";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo11";
createNode bump2d -n "bump2d11";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode lambert -n "lambert21";
createNode shadingEngine -n "lambert21SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo12";
createNode file -n "file5";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlockMini/muBlockMiniZbrushText2.png";
createNode place2dTexture -n "place2dTexture29";
createNode file -n "file6";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlockMini/muBlockMiniZbrushNorm.png";
createNode place2dTexture -n "place2dTexture30";
createNode bump2d -n "bump2d12";
	setAttr ".bd" 0.30000001192092896;
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode hyperGraphInfo -n "nodeEditorPanel1Info";
createNode hyperView -n "hyperView1";
	setAttr ".dag" no;
createNode hyperLayout -n "hyperLayout1";
	setAttr ".ihi" 0;
	setAttr ".anf" yes;
createNode phong -n "mur_V2_22229_2014:lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:materialInfo1";
createNode file -n "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture1";
createNode bump2d -n "mur_V2_22229_2014:bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture2";
createNode file -n "mur_V2_22229_2014:ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture3";
createNode lambert -n "mur_V2_22229_2014:lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "mur_V2_22229_2014:lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:materialInfo2";
createNode file -n "mur_V2_22229_2014:file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture4";
createNode file -n "mur_V2_22229_2014:file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture5";
createNode bump2d -n "mur_V2_22229_2014:bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:Mur5_optimized2014_2_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:Mur5_optimized2014_2_materialInfo1";
createNode file -n "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture1";
createNode bump2d -n "mur_V2_22229_2014:Mur5_optimized2014_2_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture2";
createNode file -n "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture3";
createNode lambert -n "mur_V2_22229_2014:Mur5_optimized2014_2_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "mur_V2_22229_2014:Mur5_optimized2014_2_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:Mur5_optimized2014_2_materialInfo2";
createNode file -n "mur_V2_22229_2014:Mur5_optimized2014_2_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4";
createNode file -n "mur_V2_22229_2014:Mur5_optimized2014_2_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5";
createNode bump2d -n "mur_V2_22229_2014:Mur5_optimized2014_2_bump2d2";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:Mur5_optimized2014_4_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:Mur5_optimized2014_4_materialInfo1";
createNode file -n "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture1";
createNode bump2d -n "mur_V2_22229_2014:Mur5_optimized2014_4_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture2";
createNode file -n "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture3";
createNode lambert -n "mur_V2_22229_2014:Mur5_optimized2014_4_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "mur_V2_22229_2014:Mur5_optimized2014_4_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:Mur5_optimized2014_4_materialInfo2";
createNode file -n "mur_V2_22229_2014:Mur5_optimized2014_4_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4";
createNode file -n "mur_V2_22229_2014:Mur5_optimized2014_4_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5";
createNode bump2d -n "mur_V2_22229_2014:Mur5_optimized2014_4_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "mur_V2_22229_2014:lambert10";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:wallSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:materialInfo3";
createNode file -n "mur_V2_22229_2014:lambert9_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture6";
createNode bump2d -n "mur_V2_22229_2014:bump2d3";
createNode file -n "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture7";
createNode file -n "mur_V2_22229_2014:lambert9_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture8";
createNode phong -n "mur_V2_22229_2014:lambert11";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:wallSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:materialInfo4";
createNode bump2d -n "mur_V2_22229_2014:bump2d4";
	setAttr ".vc1" -type "float3" 0 4.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:lambert11_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture9";
createNode file -n "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture10";
createNode file -n "mur_V2_22229_2014:lambert11_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture11";
createNode phong -n "mur_V2_22229_2014:lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:wallSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:materialInfo5";
createNode file -n "mur_V2_22229_2014:lambert12_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush1Text.png";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture12";
createNode bump2d -n "mur_V2_22229_2014:bump2d5";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush1Norm.png";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture13";
createNode file -n "mur_V2_22229_2014:lambert12_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture14";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:materialInfo1";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture1";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture3";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:lambert13";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:materialInfo2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture4";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:bump2d2";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture5";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo1";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture1";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture3";
createNode lambert -n "mur_V2_22229_2014:murPort4_2014_tri:lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_materialInfo1";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3";
createNode lambert -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_materialInfo2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_bump2d2";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_materialInfo1";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3";
createNode lambert -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_materialInfo2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:lambert10";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:wallSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:materialInfo3";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture6";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:bump2d3";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture7";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture8";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:lambert11";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:wallSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:materialInfo4";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:bump2d4";
	setAttr ".vc1" -type "float3" 0 4.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture9";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture10";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture11";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:wallSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:materialInfo5";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture12";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:bump2d5";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture13";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture14";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:lambert16";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:materialInfo6";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture15";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:bump2d6";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 1.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture16";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:lambert17";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG3";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:materialInfo7";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture17";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:bump2d7";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 1.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal_u1_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture18";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo1";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture1";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture3";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture4";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d2";
	setAttr ".bi" 1;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture5";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo1";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3";
createNode lambert -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo1";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3";
createNode lambert -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d2";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo1";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3";
createNode lambert -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert10";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo3";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture6";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d3";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture7";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture8";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo4";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d4";
	setAttr ".vc1" -type "float3" 0 4.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture9";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture10";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture11";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo5";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture12";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d5";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture13";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture14";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo6";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture15";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d6";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 1.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture16";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG3";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo7";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture17";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d7";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 1.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal_u1_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture18";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo3";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture6";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d3";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture7";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture8";
createNode lambert -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo4";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d4";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo1";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3";
createNode lambert -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d2";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_polySurface33SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo1";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d1";
	setAttr ".bi" 1;
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap";
	setAttr ".ftn" -type "string" "C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3";
createNode lambert -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9";
	setAttr ".tcf" 0.2905983030796051;
	setAttr ".trsd" 0.94017094373703003;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo2";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d2";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert10";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo5";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture11";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d5";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture12";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture13";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG1";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo6";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d6";
	setAttr ".vc1" -type "float3" 0 4.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture14";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture15";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture16";
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert13";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG2";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo7";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture17";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d7";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture18";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture19";
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:murPort2:materialInfo1";
createNode lambert -n "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1";
	setAttr ".ambc" -type "float3" 0.40000001 0.40000001 0.40000001 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F";
	setAttr ".ftn" -type "string" "murPort2.bmp";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1P2D";
createNode groupId -n "mur_V2_22229_2014:murPort4_2014_tri:groupId4";
	setAttr ".ihi" 0;
createNode lambert -n "mur_V2_22229_2014:murPort4_2014_tri:lambert18";
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:lambert18SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:materialInfo8";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:file3";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort2_texture.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:file4";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort2_normal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:bump2d8";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode phong -n "mur_V2_22229_2014:murPort4_2014_tri:lambert19";
	setAttr ".dc" 1;
	setAttr ".sc" -type "float3" 0.2 0.28999999 0.31999999 ;
	setAttr ".rfl" 0;
	setAttr ".cp" 5.429999828338623;
createNode shadingEngine -n "mur_V2_22229_2014:murPort4_2014_tri:polySurface53SG";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:murPort4_2014_tri:materialInfo9";
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort5_texture.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture21";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:bump2d9";
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort4_normal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture22";
createNode hyperGraphInfo -n "mur_V2_22229_2014:murPort4_2014_tri:nodeEditorPanel1Info";
createNode hyperView -n "mur_V2_22229_2014:murPort4_2014_tri:hyperView1";
	setAttr ".dag" no;
createNode hyperLayout -n "mur_V2_22229_2014:murPort4_2014_tri:hyperLayout1";
	setAttr ".ihi" 0;
	setAttr -s 5 ".hyp";
	setAttr ".hyp[0].nvs" 1920;
	setAttr ".hyp[1].nvs" 1920;
	setAttr ".hyp[2].nvs" 1920;
	setAttr ".hyp[3].nvs" 1920;
	setAttr ".hyp[4].nvs" 1920;
	setAttr ".anf" yes;
createNode file -n "mur_V2_22229_2014:murPort4_2014_tri:file5";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort4_normal.png";
createNode place2dTexture -n "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23";
createNode bump2d -n "mur_V2_22229_2014:murPort4_2014_tri:bump2d10";
	setAttr ".vc1" -type "float3" 0 1.9999999e-005 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode shadingEngine -n "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "mur_V2_22229_2014:MurV2exportFromZbrush:materialInfo1";
createNode lambert -n "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1";
	setAttr ".ambc" -type "float3" 0.40000001 0.40000001 0.40000001 ;
createNode file -n "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F";
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush3Text.png";
createNode place2dTexture -n "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1P2D";
createNode file -n "mur_V2_22229_2014:file3";
	setAttr ".ail" yes;
	setAttr ".ftn" -type "string" "C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush3Norm.png";
createNode place2dTexture -n "mur_V2_22229_2014:place2dTexture15";
createNode bump2d -n "mur_V2_22229_2014:bump2d6";
	setAttr ".vc1" -type "float3" 0 9.9999997e-006 0 ;
	setAttr ".vc2" -type "float3" 9.9999997e-006 9.9999997e-006 0 ;
createNode hyperGraphInfo -n "mur_V2_22229_2014:nodeEditorPanel1Info";
createNode hyperView -n "mur_V2_22229_2014:hyperView1";
	setAttr ".dag" no;
createNode hyperLayout -n "mur_V2_22229_2014:hyperLayout1";
	setAttr ".ihi" 0;
	setAttr ".anf" yes;
select -ne :time1;
	setAttr ".o" 1;
	setAttr ".unw" 1;
select -ne :renderPartition;
	setAttr -s 113 ".st";
select -ne :initialShadingGroup;
	setAttr ".ro" yes;
select -ne :initialParticleSE;
	setAttr ".ro" yes;
select -ne :defaultShaderList1;
	setAttr -s 95 ".s";
select -ne :defaultTextureList1;
	setAttr -s 272 ".tx";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderUtilityList1;
	setAttr -s 381 ".u";
select -ne :defaultRenderingList1;
select -ne :renderGlobalsList1;
select -ne :defaultResolution;
	setAttr ".pa" 1;
select -ne :hardwareRenderGlobals;
	setAttr ".ctrs" 256;
	setAttr ".btrs" 512;
select -ne :hardwareRenderingGlobals;
	setAttr ".otfna" -type "stringArray" 22 "NURBS Curves" "NURBS Surfaces" "Polygons" "Subdiv Surface" "Particles" "Particle Instance" "Fluids" "Strokes" "Image Planes" "UI" "Lights" "Cameras" "Locators" "Joints" "IK Handles" "Deformers" "Motion Trails" "Components" "Hair Systems" "Follicles" "Misc. UI" "Ornaments"  ;
	setAttr ".otfva" -type "Int32Array" 22 0 1 1 1 1 1
		 1 1 1 0 0 0 0 0 0 0 0 0
		 0 0 0 0 ;
select -ne :defaultHardwareRenderGlobals;
	setAttr ".fn" -type "string" "im";
	setAttr ".res" -type "string" "ntsc_4d 646 485 1.333";
select -ne :ikSystem;
	setAttr -s 4 ".sol";
connectAttr ":mentalrayGlobals.msg" ":mentalrayItemsList.glb";
connectAttr ":miDefaultOptions.msg" ":mentalrayItemsList.opt" -na;
connectAttr ":miDefaultFramebuffer.msg" ":mentalrayItemsList.fb" -na;
connectAttr ":miDefaultOptions.msg" ":mentalrayGlobals.opt";
connectAttr ":miDefaultFramebuffer.msg" ":mentalrayGlobals.fb";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallBlockSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallBlockSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallBlockSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallBlockSG3.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini5_2014_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini5_2014_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_polySurface33SG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_lambert9SG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "pasted__Mur5_optimized2014_lambert9SG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "polySurface34SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "polySurface34SG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "polySurface34SG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_5_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_5_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini5_2014_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini5_2014_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini5_2014_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini5_2014_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini5_2014_wallSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini5_2014_wallSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_polySurface33SG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_lambert9SG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_pasted__Mur5_optimized2014_lambert9SG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_polySurface34SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_polySurface34SG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_polySurface34SG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_5_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_5_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_wallSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "murBlockMini1_2014_wallSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_5_polySurface33SG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_5_lambert9SG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_5_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_5_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_5_wallSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Mur5_optimized2014_5_wallSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallBlockMiniSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallBlockMiniSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "lambert18SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallBlockMiniSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "wallBlockMiniSG3.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "lambert21SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:wallSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:wallSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:wallSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG3.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG3.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG1.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG2.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:lambert18SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:polySurface53SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallBlockSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallBlockSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallBlockSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallBlockSG3.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini5_2014_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini5_2014_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_polySurface33SG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_lambert9SG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "pasted__Mur5_optimized2014_lambert9SG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "polySurface34SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "polySurface34SG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "polySurface34SG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_5_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_5_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini5_2014_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini5_2014_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini5_2014_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini5_2014_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini5_2014_wallSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini5_2014_wallSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_polySurface33SG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_lambert9SG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_pasted__Mur5_optimized2014_lambert9SG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_polySurface34SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_polySurface34SG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_polySurface34SG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_5_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_5_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_wallSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "murBlockMini1_2014_wallSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_5_polySurface33SG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_5_lambert9SG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_5_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_5_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_5_wallSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Mur5_optimized2014_5_wallSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallBlockMiniSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallBlockMiniSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "lambert18SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallBlockMiniSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "wallBlockMiniSG3.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "lambert21SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:wallSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:wallSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:wallSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG3.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG3.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_polySurface33SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG1.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG2.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:lambert18SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:murPort4_2014_tri:polySurface53SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr "lambert12_Flattened_Diffuse.oc" "lambert12.c";
connectAttr "bump2d1.o" "lambert12.n";
connectAttr "ReflectionMap.oc" "lambert12.rc";
connectAttr "lambert12.oc" "wallBlockSG.ss";
connectAttr "wallBlockSG.msg" "materialInfo1.sg";
connectAttr "lambert12.msg" "materialInfo1.m";
connectAttr "lambert12_Flattened_Diffuse.msg" "materialInfo1.t" -na;
connectAttr "place2dTexture1.o" "lambert12_Flattened_Diffuse.uv";
connectAttr "place2dTexture1.ofu" "lambert12_Flattened_Diffuse.ofu";
connectAttr "place2dTexture1.ofv" "lambert12_Flattened_Diffuse.ofv";
connectAttr "place2dTexture1.rf" "lambert12_Flattened_Diffuse.rf";
connectAttr "place2dTexture1.reu" "lambert12_Flattened_Diffuse.reu";
connectAttr "place2dTexture1.rev" "lambert12_Flattened_Diffuse.rev";
connectAttr "place2dTexture1.vt1" "lambert12_Flattened_Diffuse.vt1";
connectAttr "place2dTexture1.vt2" "lambert12_Flattened_Diffuse.vt2";
connectAttr "place2dTexture1.vt3" "lambert12_Flattened_Diffuse.vt3";
connectAttr "place2dTexture1.vc1" "lambert12_Flattened_Diffuse.vc1";
connectAttr "place2dTexture1.ofs" "lambert12_Flattened_Diffuse.fs";
connectAttr "lambert12_Flattened_NormalFBXASC032Map.oa" "bump2d1.bv";
connectAttr "place2dTexture2.o" "lambert12_Flattened_NormalFBXASC032Map.uv";
connectAttr "place2dTexture2.ofu" "lambert12_Flattened_NormalFBXASC032Map.ofu";
connectAttr "place2dTexture2.ofv" "lambert12_Flattened_NormalFBXASC032Map.ofv";
connectAttr "place2dTexture2.rf" "lambert12_Flattened_NormalFBXASC032Map.rf";
connectAttr "place2dTexture2.reu" "lambert12_Flattened_NormalFBXASC032Map.reu";
connectAttr "place2dTexture2.rev" "lambert12_Flattened_NormalFBXASC032Map.rev";
connectAttr "place2dTexture2.vt1" "lambert12_Flattened_NormalFBXASC032Map.vt1";
connectAttr "place2dTexture2.vt2" "lambert12_Flattened_NormalFBXASC032Map.vt2";
connectAttr "place2dTexture2.vt3" "lambert12_Flattened_NormalFBXASC032Map.vt3";
connectAttr "place2dTexture2.vc1" "lambert12_Flattened_NormalFBXASC032Map.vc1";
connectAttr "place2dTexture2.ofs" "lambert12_Flattened_NormalFBXASC032Map.fs";
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
connectAttr "lambert13_Flattened_Diffuse.oc" "lambert13.c";
connectAttr "bump2d2.o" "lambert13.n";
connectAttr "ReflectionMap.oc" "lambert13.rc";
connectAttr "lambert13.oc" "wallBlockSG1.ss";
connectAttr "wallBlockSG1.msg" "materialInfo2.sg";
connectAttr "lambert13.msg" "materialInfo2.m";
connectAttr "lambert13_Flattened_Diffuse.msg" "materialInfo2.t" -na;
connectAttr "place2dTexture4.o" "lambert13_Flattened_Diffuse.uv";
connectAttr "place2dTexture4.ofu" "lambert13_Flattened_Diffuse.ofu";
connectAttr "place2dTexture4.ofv" "lambert13_Flattened_Diffuse.ofv";
connectAttr "place2dTexture4.rf" "lambert13_Flattened_Diffuse.rf";
connectAttr "place2dTexture4.reu" "lambert13_Flattened_Diffuse.reu";
connectAttr "place2dTexture4.rev" "lambert13_Flattened_Diffuse.rev";
connectAttr "place2dTexture4.vt1" "lambert13_Flattened_Diffuse.vt1";
connectAttr "place2dTexture4.vt2" "lambert13_Flattened_Diffuse.vt2";
connectAttr "place2dTexture4.vt3" "lambert13_Flattened_Diffuse.vt3";
connectAttr "place2dTexture4.vc1" "lambert13_Flattened_Diffuse.vc1";
connectAttr "place2dTexture4.ofs" "lambert13_Flattened_Diffuse.fs";
connectAttr "lambert13_Flattened_NormalFBXASC032Map.oa" "bump2d2.bv";
connectAttr "place2dTexture5.o" "lambert13_Flattened_NormalFBXASC032Map.uv";
connectAttr "place2dTexture5.ofu" "lambert13_Flattened_NormalFBXASC032Map.ofu";
connectAttr "place2dTexture5.ofv" "lambert13_Flattened_NormalFBXASC032Map.ofv";
connectAttr "place2dTexture5.rf" "lambert13_Flattened_NormalFBXASC032Map.rf";
connectAttr "place2dTexture5.reu" "lambert13_Flattened_NormalFBXASC032Map.reu";
connectAttr "place2dTexture5.rev" "lambert13_Flattened_NormalFBXASC032Map.rev";
connectAttr "place2dTexture5.vt1" "lambert13_Flattened_NormalFBXASC032Map.vt1";
connectAttr "place2dTexture5.vt2" "lambert13_Flattened_NormalFBXASC032Map.vt2";
connectAttr "place2dTexture5.vt3" "lambert13_Flattened_NormalFBXASC032Map.vt3";
connectAttr "place2dTexture5.vc1" "lambert13_Flattened_NormalFBXASC032Map.vc1";
connectAttr "place2dTexture5.ofs" "lambert13_Flattened_NormalFBXASC032Map.fs";
connectAttr "lambert8_Flattened_Diffuse_u1_v1.oc" "lambert8.c";
connectAttr "mur22227_bump2d1.o" "lambert8.n";
connectAttr "mur22227_ReflectionMap.oc" "lambert8.rc";
connectAttr "lambert8.oc" "polySurface33SG.ss";
connectAttr "polySurface33SG.msg" "mur22227_materialInfo1.sg";
connectAttr "lambert8.msg" "mur22227_materialInfo1.m";
connectAttr "lambert8_Flattened_Diffuse_u1_v1.msg" "mur22227_materialInfo1.t" -na
		;
connectAttr "mur22227_place2dTexture1.o" "lambert8_Flattened_Diffuse_u1_v1.uv";
connectAttr "mur22227_place2dTexture1.ofu" "lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur22227_place2dTexture1.ofv" "lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur22227_place2dTexture1.rf" "lambert8_Flattened_Diffuse_u1_v1.rf";
connectAttr "mur22227_place2dTexture1.reu" "lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur22227_place2dTexture1.rev" "lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur22227_place2dTexture1.vt1" "lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur22227_place2dTexture1.vt2" "lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur22227_place2dTexture1.vt3" "lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur22227_place2dTexture1.vc1" "lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur22227_place2dTexture1.ofs" "lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur22227_bump2d1.bv"
		;
connectAttr "mur22227_place2dTexture2.o" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur22227_place2dTexture2.ofu" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur22227_place2dTexture2.ofv" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur22227_place2dTexture2.rf" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur22227_place2dTexture2.reu" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur22227_place2dTexture2.rev" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur22227_place2dTexture2.vt1" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur22227_place2dTexture2.vt2" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur22227_place2dTexture2.vt3" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur22227_place2dTexture2.vc1" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur22227_place2dTexture2.ofs" "lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur22227_place2dTexture3.o" "mur22227_ReflectionMap.uv";
connectAttr "mur22227_place2dTexture3.ofu" "mur22227_ReflectionMap.ofu";
connectAttr "mur22227_place2dTexture3.ofv" "mur22227_ReflectionMap.ofv";
connectAttr "mur22227_place2dTexture3.rf" "mur22227_ReflectionMap.rf";
connectAttr "mur22227_place2dTexture3.reu" "mur22227_ReflectionMap.reu";
connectAttr "mur22227_place2dTexture3.rev" "mur22227_ReflectionMap.rev";
connectAttr "mur22227_place2dTexture3.vt1" "mur22227_ReflectionMap.vt1";
connectAttr "mur22227_place2dTexture3.vt2" "mur22227_ReflectionMap.vt2";
connectAttr "mur22227_place2dTexture3.vt3" "mur22227_ReflectionMap.vt3";
connectAttr "mur22227_place2dTexture3.vc1" "mur22227_ReflectionMap.vc1";
connectAttr "mur22227_place2dTexture3.ofs" "mur22227_ReflectionMap.fs";
connectAttr "file1.oc" "lambert9.c";
connectAttr "file1.ot" "lambert9.it";
connectAttr "mur22227_bump2d2.o" "lambert9.n";
connectAttr "lambert9.oc" "lambert9SG.ss";
connectAttr "lambert9SG.msg" "mur22227_materialInfo2.sg";
connectAttr "lambert9.msg" "mur22227_materialInfo2.m";
connectAttr "file1.msg" "mur22227_materialInfo2.t" -na;
connectAttr "mur22227_place2dTexture4.c" "file1.c";
connectAttr "mur22227_place2dTexture4.tf" "file1.tf";
connectAttr "mur22227_place2dTexture4.rf" "file1.rf";
connectAttr "mur22227_place2dTexture4.mu" "file1.mu";
connectAttr "mur22227_place2dTexture4.mv" "file1.mv";
connectAttr "mur22227_place2dTexture4.s" "file1.s";
connectAttr "mur22227_place2dTexture4.wu" "file1.wu";
connectAttr "mur22227_place2dTexture4.wv" "file1.wv";
connectAttr "mur22227_place2dTexture4.re" "file1.re";
connectAttr "mur22227_place2dTexture4.of" "file1.of";
connectAttr "mur22227_place2dTexture4.r" "file1.ro";
connectAttr "mur22227_place2dTexture4.n" "file1.n";
connectAttr "mur22227_place2dTexture4.vt1" "file1.vt1";
connectAttr "mur22227_place2dTexture4.vt2" "file1.vt2";
connectAttr "mur22227_place2dTexture4.vt3" "file1.vt3";
connectAttr "mur22227_place2dTexture4.vc1" "file1.vc1";
connectAttr "mur22227_place2dTexture4.o" "file1.uv";
connectAttr "mur22227_place2dTexture4.ofs" "file1.fs";
connectAttr "mur22227_place2dTexture5.c" "file2.c";
connectAttr "mur22227_place2dTexture5.tf" "file2.tf";
connectAttr "mur22227_place2dTexture5.rf" "file2.rf";
connectAttr "mur22227_place2dTexture5.mu" "file2.mu";
connectAttr "mur22227_place2dTexture5.mv" "file2.mv";
connectAttr "mur22227_place2dTexture5.s" "file2.s";
connectAttr "mur22227_place2dTexture5.wu" "file2.wu";
connectAttr "mur22227_place2dTexture5.wv" "file2.wv";
connectAttr "mur22227_place2dTexture5.re" "file2.re";
connectAttr "mur22227_place2dTexture5.of" "file2.of";
connectAttr "mur22227_place2dTexture5.r" "file2.ro";
connectAttr "mur22227_place2dTexture5.n" "file2.n";
connectAttr "mur22227_place2dTexture5.vt1" "file2.vt1";
connectAttr "mur22227_place2dTexture5.vt2" "file2.vt2";
connectAttr "mur22227_place2dTexture5.vt3" "file2.vt3";
connectAttr "mur22227_place2dTexture5.vc1" "file2.vc1";
connectAttr "mur22227_place2dTexture5.o" "file2.uv";
connectAttr "mur22227_place2dTexture5.ofs" "file2.fs";
connectAttr "file2.oa" "mur22227_bump2d2.bv";
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
connectAttr "mur22227_ReflectionMap.oc" "lambert11.rc";
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
connectAttr "mur22227_lambert12_Flattened_Diffuse.oc" "mur22227_lambert12.c";
connectAttr "bump2d5.o" "mur22227_lambert12.n";
connectAttr "lambert12_Flattened_Opacity.ot" "mur22227_lambert12.it";
connectAttr "mur22227_ReflectionMap.oc" "mur22227_lambert12.rc";
connectAttr "mur22227_lambert12.oc" "wallSG2.ss";
connectAttr "wallSG2.msg" "materialInfo5.sg";
connectAttr "mur22227_lambert12.msg" "materialInfo5.m";
connectAttr "mur22227_lambert12_Flattened_Diffuse.msg" "materialInfo5.t" -na;
connectAttr "place2dTexture12.o" "mur22227_lambert12_Flattened_Diffuse.uv";
connectAttr "place2dTexture12.ofu" "mur22227_lambert12_Flattened_Diffuse.ofu";
connectAttr "place2dTexture12.ofv" "mur22227_lambert12_Flattened_Diffuse.ofv";
connectAttr "place2dTexture12.rf" "mur22227_lambert12_Flattened_Diffuse.rf";
connectAttr "place2dTexture12.reu" "mur22227_lambert12_Flattened_Diffuse.reu";
connectAttr "place2dTexture12.rev" "mur22227_lambert12_Flattened_Diffuse.rev";
connectAttr "place2dTexture12.vt1" "mur22227_lambert12_Flattened_Diffuse.vt1";
connectAttr "place2dTexture12.vt2" "mur22227_lambert12_Flattened_Diffuse.vt2";
connectAttr "place2dTexture12.vt3" "mur22227_lambert12_Flattened_Diffuse.vt3";
connectAttr "place2dTexture12.vc1" "mur22227_lambert12_Flattened_Diffuse.vc1";
connectAttr "place2dTexture12.ofs" "mur22227_lambert12_Flattened_Diffuse.fs";
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
connectAttr "lambert16_Flattened_Diffuse_u1_v1.oc" "lambert16.c";
connectAttr "bump2d6.o" "lambert16.n";
connectAttr "ReflectionMap.oc" "lambert16.rc";
connectAttr "lambert16.oc" "wallBlockSG2.ss";
connectAttr "wallBlockSG2.msg" "materialInfo6.sg";
connectAttr "lambert16.msg" "materialInfo6.m";
connectAttr "lambert16_Flattened_Diffuse_u1_v1.msg" "materialInfo6.t" -na;
connectAttr "place2dTexture15.o" "lambert16_Flattened_Diffuse_u1_v1.uv";
connectAttr "place2dTexture15.ofu" "lambert16_Flattened_Diffuse_u1_v1.ofu";
connectAttr "place2dTexture15.ofv" "lambert16_Flattened_Diffuse_u1_v1.ofv";
connectAttr "place2dTexture15.rf" "lambert16_Flattened_Diffuse_u1_v1.rf";
connectAttr "place2dTexture15.reu" "lambert16_Flattened_Diffuse_u1_v1.reu";
connectAttr "place2dTexture15.rev" "lambert16_Flattened_Diffuse_u1_v1.rev";
connectAttr "place2dTexture15.vt1" "lambert16_Flattened_Diffuse_u1_v1.vt1";
connectAttr "place2dTexture15.vt2" "lambert16_Flattened_Diffuse_u1_v1.vt2";
connectAttr "place2dTexture15.vt3" "lambert16_Flattened_Diffuse_u1_v1.vt3";
connectAttr "place2dTexture15.vc1" "lambert16_Flattened_Diffuse_u1_v1.vc1";
connectAttr "place2dTexture15.ofs" "lambert16_Flattened_Diffuse_u1_v1.fs";
connectAttr "lambert16_Flattened_NormalFBXASC032Map_u1_v1.oa" "bump2d6.bv";
connectAttr "place2dTexture16.o" "lambert16_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "place2dTexture16.ofu" "lambert16_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "place2dTexture16.ofv" "lambert16_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "place2dTexture16.rf" "lambert16_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "place2dTexture16.reu" "lambert16_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "place2dTexture16.rev" "lambert16_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "place2dTexture16.vt1" "lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "place2dTexture16.vt2" "lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "place2dTexture16.vt3" "lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "place2dTexture16.vc1" "lambert16_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "place2dTexture16.ofs" "lambert16_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "lambert17_Flattened_Diffuse_u1_v1.oc" "lambert17.c";
connectAttr "bump2d7.o" "lambert17.n";
connectAttr "ReflectionMap.oc" "lambert17.rc";
connectAttr "lambert17.oc" "wallBlockSG3.ss";
connectAttr "wallBlockSG3.msg" "materialInfo7.sg";
connectAttr "lambert17.msg" "materialInfo7.m";
connectAttr "lambert17_Flattened_Diffuse_u1_v1.msg" "materialInfo7.t" -na;
connectAttr "place2dTexture17.o" "lambert17_Flattened_Diffuse_u1_v1.uv";
connectAttr "place2dTexture17.ofu" "lambert17_Flattened_Diffuse_u1_v1.ofu";
connectAttr "place2dTexture17.ofv" "lambert17_Flattened_Diffuse_u1_v1.ofv";
connectAttr "place2dTexture17.rf" "lambert17_Flattened_Diffuse_u1_v1.rf";
connectAttr "place2dTexture17.reu" "lambert17_Flattened_Diffuse_u1_v1.reu";
connectAttr "place2dTexture17.rev" "lambert17_Flattened_Diffuse_u1_v1.rev";
connectAttr "place2dTexture17.vt1" "lambert17_Flattened_Diffuse_u1_v1.vt1";
connectAttr "place2dTexture17.vt2" "lambert17_Flattened_Diffuse_u1_v1.vt2";
connectAttr "place2dTexture17.vt3" "lambert17_Flattened_Diffuse_u1_v1.vt3";
connectAttr "place2dTexture17.vc1" "lambert17_Flattened_Diffuse_u1_v1.vc1";
connectAttr "place2dTexture17.ofs" "lambert17_Flattened_Diffuse_u1_v1.fs";
connectAttr "lambert17_Flattened_BumpFBXASC032Map_u1_v1.oa" "bump2d7.bv";
connectAttr "place2dTexture18.o" "lambert17_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "place2dTexture18.ofu" "lambert17_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "place2dTexture18.ofv" "lambert17_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "place2dTexture18.rf" "lambert17_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "place2dTexture18.reu" "lambert17_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "place2dTexture18.rev" "lambert17_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "place2dTexture18.vt1" "lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "place2dTexture18.vt2" "lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "place2dTexture18.vt3" "lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "place2dTexture18.vc1" "lambert17_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "place2dTexture18.ofs" "lambert17_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murBlockMini5_2014_polySurface33SG.msg" "murBlockMini5_2014_materialInfo1.sg"
		;
connectAttr "murBlockMini5_2014_place2dTexture1.o" "murBlockMini5_2014_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture1.ofu" "murBlockMini5_2014_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murBlockMini5_2014_place2dTexture1.ofv" "murBlockMini5_2014_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murBlockMini5_2014_place2dTexture1.rf" "murBlockMini5_2014_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture1.reu" "murBlockMini5_2014_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murBlockMini5_2014_place2dTexture1.rev" "murBlockMini5_2014_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murBlockMini5_2014_place2dTexture1.vt1" "murBlockMini5_2014_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture1.vt2" "murBlockMini5_2014_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture1.vt3" "murBlockMini5_2014_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture1.vc1" "murBlockMini5_2014_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture1.ofs" "murBlockMini5_2014_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murBlockMini5_2014_bump2d1.bv"
		;
connectAttr "murBlockMini5_2014_place2dTexture2.o" "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture2.ofu" "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murBlockMini5_2014_place2dTexture2.ofv" "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murBlockMini5_2014_place2dTexture2.rf" "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture2.reu" "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murBlockMini5_2014_place2dTexture2.rev" "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murBlockMini5_2014_place2dTexture2.vt1" "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture2.vt2" "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture2.vt3" "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture2.vc1" "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture2.ofs" "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murBlockMini5_2014_place2dTexture3.o" "murBlockMini5_2014_ReflectionMap.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture3.ofu" "murBlockMini5_2014_ReflectionMap.ofu"
		;
connectAttr "murBlockMini5_2014_place2dTexture3.ofv" "murBlockMini5_2014_ReflectionMap.ofv"
		;
connectAttr "murBlockMini5_2014_place2dTexture3.rf" "murBlockMini5_2014_ReflectionMap.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture3.reu" "murBlockMini5_2014_ReflectionMap.reu"
		;
connectAttr "murBlockMini5_2014_place2dTexture3.rev" "murBlockMini5_2014_ReflectionMap.rev"
		;
connectAttr "murBlockMini5_2014_place2dTexture3.vt1" "murBlockMini5_2014_ReflectionMap.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture3.vt2" "murBlockMini5_2014_ReflectionMap.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture3.vt3" "murBlockMini5_2014_ReflectionMap.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture3.vc1" "murBlockMini5_2014_ReflectionMap.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture3.ofs" "murBlockMini5_2014_ReflectionMap.fs"
		;
connectAttr "murBlockMini5_2014_lambert9SG.msg" "murBlockMini5_2014_materialInfo2.sg"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.c" "murBlockMini5_2014_file1.c";
connectAttr "murBlockMini5_2014_place2dTexture4.tf" "murBlockMini5_2014_file1.tf"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.rf" "murBlockMini5_2014_file1.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.mu" "murBlockMini5_2014_file1.mu"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.mv" "murBlockMini5_2014_file1.mv"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.s" "murBlockMini5_2014_file1.s";
connectAttr "murBlockMini5_2014_place2dTexture4.wu" "murBlockMini5_2014_file1.wu"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.wv" "murBlockMini5_2014_file1.wv"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.re" "murBlockMini5_2014_file1.re"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.of" "murBlockMini5_2014_file1.of"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.r" "murBlockMini5_2014_file1.ro"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.n" "murBlockMini5_2014_file1.n";
connectAttr "murBlockMini5_2014_place2dTexture4.vt1" "murBlockMini5_2014_file1.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.vt2" "murBlockMini5_2014_file1.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.vt3" "murBlockMini5_2014_file1.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.vc1" "murBlockMini5_2014_file1.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.o" "murBlockMini5_2014_file1.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture4.ofs" "murBlockMini5_2014_file1.fs"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.c" "murBlockMini5_2014_file2.c";
connectAttr "murBlockMini5_2014_place2dTexture5.tf" "murBlockMini5_2014_file2.tf"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.rf" "murBlockMini5_2014_file2.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.mu" "murBlockMini5_2014_file2.mu"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.mv" "murBlockMini5_2014_file2.mv"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.s" "murBlockMini5_2014_file2.s";
connectAttr "murBlockMini5_2014_place2dTexture5.wu" "murBlockMini5_2014_file2.wu"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.wv" "murBlockMini5_2014_file2.wv"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.re" "murBlockMini5_2014_file2.re"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.of" "murBlockMini5_2014_file2.of"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.r" "murBlockMini5_2014_file2.ro"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.n" "murBlockMini5_2014_file2.n";
connectAttr "murBlockMini5_2014_place2dTexture5.vt1" "murBlockMini5_2014_file2.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.vt2" "murBlockMini5_2014_file2.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.vt3" "murBlockMini5_2014_file2.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.vc1" "murBlockMini5_2014_file2.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.o" "murBlockMini5_2014_file2.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture5.ofs" "murBlockMini5_2014_file2.fs"
		;
connectAttr "murBlockMini5_2014_file2.oa" "murBlockMini5_2014_bump2d2.bv";
connectAttr "Mur5_optimized2014_polySurface33SG.msg" "Mur5_optimized2014_materialInfo1.sg"
		;
connectAttr "Mur5_optimized2014_place2dTexture1.o" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "Mur5_optimized2014_place2dTexture1.ofu" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "Mur5_optimized2014_place2dTexture1.ofv" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "Mur5_optimized2014_place2dTexture1.rf" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "Mur5_optimized2014_place2dTexture1.reu" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "Mur5_optimized2014_place2dTexture1.rev" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "Mur5_optimized2014_place2dTexture1.vt1" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "Mur5_optimized2014_place2dTexture1.vt2" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "Mur5_optimized2014_place2dTexture1.vt3" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "Mur5_optimized2014_place2dTexture1.vc1" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "Mur5_optimized2014_place2dTexture1.ofs" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "Mur5_optimized2014_bump2d1.bv"
		;
connectAttr "Mur5_optimized2014_place2dTexture2.o" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "Mur5_optimized2014_place2dTexture2.ofu" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "Mur5_optimized2014_place2dTexture2.ofv" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "Mur5_optimized2014_place2dTexture2.rf" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "Mur5_optimized2014_place2dTexture2.reu" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "Mur5_optimized2014_place2dTexture2.rev" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "Mur5_optimized2014_place2dTexture2.vt1" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "Mur5_optimized2014_place2dTexture2.vt2" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "Mur5_optimized2014_place2dTexture2.vt3" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "Mur5_optimized2014_place2dTexture2.vc1" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "Mur5_optimized2014_place2dTexture2.ofs" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "Mur5_optimized2014_place2dTexture3.o" "Mur5_optimized2014_ReflectionMap.uv"
		;
connectAttr "Mur5_optimized2014_place2dTexture3.ofu" "Mur5_optimized2014_ReflectionMap.ofu"
		;
connectAttr "Mur5_optimized2014_place2dTexture3.ofv" "Mur5_optimized2014_ReflectionMap.ofv"
		;
connectAttr "Mur5_optimized2014_place2dTexture3.rf" "Mur5_optimized2014_ReflectionMap.rf"
		;
connectAttr "Mur5_optimized2014_place2dTexture3.reu" "Mur5_optimized2014_ReflectionMap.reu"
		;
connectAttr "Mur5_optimized2014_place2dTexture3.rev" "Mur5_optimized2014_ReflectionMap.rev"
		;
connectAttr "Mur5_optimized2014_place2dTexture3.vt1" "Mur5_optimized2014_ReflectionMap.vt1"
		;
connectAttr "Mur5_optimized2014_place2dTexture3.vt2" "Mur5_optimized2014_ReflectionMap.vt2"
		;
connectAttr "Mur5_optimized2014_place2dTexture3.vt3" "Mur5_optimized2014_ReflectionMap.vt3"
		;
connectAttr "Mur5_optimized2014_place2dTexture3.vc1" "Mur5_optimized2014_ReflectionMap.vc1"
		;
connectAttr "Mur5_optimized2014_place2dTexture3.ofs" "Mur5_optimized2014_ReflectionMap.fs"
		;
connectAttr "Mur5_optimized2014_lambert9SG.msg" "Mur5_optimized2014_materialInfo2.sg"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.c" "Mur5_optimized2014_file1.c";
connectAttr "Mur5_optimized2014_place2dTexture4.tf" "Mur5_optimized2014_file1.tf"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.rf" "Mur5_optimized2014_file1.rf"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.mu" "Mur5_optimized2014_file1.mu"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.mv" "Mur5_optimized2014_file1.mv"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.s" "Mur5_optimized2014_file1.s";
connectAttr "Mur5_optimized2014_place2dTexture4.wu" "Mur5_optimized2014_file1.wu"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.wv" "Mur5_optimized2014_file1.wv"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.re" "Mur5_optimized2014_file1.re"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.of" "Mur5_optimized2014_file1.of"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.r" "Mur5_optimized2014_file1.ro"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.n" "Mur5_optimized2014_file1.n";
connectAttr "Mur5_optimized2014_place2dTexture4.vt1" "Mur5_optimized2014_file1.vt1"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.vt2" "Mur5_optimized2014_file1.vt2"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.vt3" "Mur5_optimized2014_file1.vt3"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.vc1" "Mur5_optimized2014_file1.vc1"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.o" "Mur5_optimized2014_file1.uv"
		;
connectAttr "Mur5_optimized2014_place2dTexture4.ofs" "Mur5_optimized2014_file1.fs"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.c" "Mur5_optimized2014_file2.c";
connectAttr "Mur5_optimized2014_place2dTexture5.tf" "Mur5_optimized2014_file2.tf"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.rf" "Mur5_optimized2014_file2.rf"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.mu" "Mur5_optimized2014_file2.mu"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.mv" "Mur5_optimized2014_file2.mv"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.s" "Mur5_optimized2014_file2.s";
connectAttr "Mur5_optimized2014_place2dTexture5.wu" "Mur5_optimized2014_file2.wu"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.wv" "Mur5_optimized2014_file2.wv"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.re" "Mur5_optimized2014_file2.re"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.of" "Mur5_optimized2014_file2.of"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.r" "Mur5_optimized2014_file2.ro"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.n" "Mur5_optimized2014_file2.n";
connectAttr "Mur5_optimized2014_place2dTexture5.vt1" "Mur5_optimized2014_file2.vt1"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.vt2" "Mur5_optimized2014_file2.vt2"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.vt3" "Mur5_optimized2014_file2.vt3"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.vc1" "Mur5_optimized2014_file2.vc1"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.o" "Mur5_optimized2014_file2.uv"
		;
connectAttr "Mur5_optimized2014_place2dTexture5.ofs" "Mur5_optimized2014_file2.fs"
		;
connectAttr "Mur5_optimized2014_file2.oa" "Mur5_optimized2014_bump2d2.bv";
connectAttr "Mur5_optimized2014_polySurface33SG1.msg" "Mur5_optimized2014_materialInfo3.sg"
		;
connectAttr "Mur5_optimized2014_place2dTexture6.o" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.uv"
		;
connectAttr "Mur5_optimized2014_place2dTexture6.ofu" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.ofu"
		;
connectAttr "Mur5_optimized2014_place2dTexture6.ofv" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.ofv"
		;
connectAttr "Mur5_optimized2014_place2dTexture6.rf" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.rf"
		;
connectAttr "Mur5_optimized2014_place2dTexture6.reu" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.reu"
		;
connectAttr "Mur5_optimized2014_place2dTexture6.rev" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.rev"
		;
connectAttr "Mur5_optimized2014_place2dTexture6.vt1" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.vt1"
		;
connectAttr "Mur5_optimized2014_place2dTexture6.vt2" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.vt2"
		;
connectAttr "Mur5_optimized2014_place2dTexture6.vt3" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.vt3"
		;
connectAttr "Mur5_optimized2014_place2dTexture6.vc1" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.vc1"
		;
connectAttr "Mur5_optimized2014_place2dTexture6.ofs" "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.fs"
		;
connectAttr "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.oa" "Mur5_optimized2014_bump2d3.bv"
		;
connectAttr "Mur5_optimized2014_place2dTexture7.o" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.uv"
		;
connectAttr "Mur5_optimized2014_place2dTexture7.ofu" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.ofu"
		;
connectAttr "Mur5_optimized2014_place2dTexture7.ofv" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.ofv"
		;
connectAttr "Mur5_optimized2014_place2dTexture7.rf" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.rf"
		;
connectAttr "Mur5_optimized2014_place2dTexture7.reu" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.reu"
		;
connectAttr "Mur5_optimized2014_place2dTexture7.rev" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.rev"
		;
connectAttr "Mur5_optimized2014_place2dTexture7.vt1" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.vt1"
		;
connectAttr "Mur5_optimized2014_place2dTexture7.vt2" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.vt2"
		;
connectAttr "Mur5_optimized2014_place2dTexture7.vt3" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.vt3"
		;
connectAttr "Mur5_optimized2014_place2dTexture7.vc1" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.vc1"
		;
connectAttr "Mur5_optimized2014_place2dTexture7.ofs" "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.fs"
		;
connectAttr "Mur5_optimized2014_place2dTexture8.o" "Mur5_optimized2014_ReflectionMap1.uv"
		;
connectAttr "Mur5_optimized2014_place2dTexture8.ofu" "Mur5_optimized2014_ReflectionMap1.ofu"
		;
connectAttr "Mur5_optimized2014_place2dTexture8.ofv" "Mur5_optimized2014_ReflectionMap1.ofv"
		;
connectAttr "Mur5_optimized2014_place2dTexture8.rf" "Mur5_optimized2014_ReflectionMap1.rf"
		;
connectAttr "Mur5_optimized2014_place2dTexture8.reu" "Mur5_optimized2014_ReflectionMap1.reu"
		;
connectAttr "Mur5_optimized2014_place2dTexture8.rev" "Mur5_optimized2014_ReflectionMap1.rev"
		;
connectAttr "Mur5_optimized2014_place2dTexture8.vt1" "Mur5_optimized2014_ReflectionMap1.vt1"
		;
connectAttr "Mur5_optimized2014_place2dTexture8.vt2" "Mur5_optimized2014_ReflectionMap1.vt2"
		;
connectAttr "Mur5_optimized2014_place2dTexture8.vt3" "Mur5_optimized2014_ReflectionMap1.vt3"
		;
connectAttr "Mur5_optimized2014_place2dTexture8.vc1" "Mur5_optimized2014_ReflectionMap1.vc1"
		;
connectAttr "Mur5_optimized2014_place2dTexture8.ofs" "Mur5_optimized2014_ReflectionMap1.fs"
		;
connectAttr "Mur5_optimized2014_lambert9SG1.msg" "Mur5_optimized2014_materialInfo4.sg"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.c" "Mur5_optimized2014_file3.c";
connectAttr "Mur5_optimized2014_place2dTexture9.tf" "Mur5_optimized2014_file3.tf"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.rf" "Mur5_optimized2014_file3.rf"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.mu" "Mur5_optimized2014_file3.mu"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.mv" "Mur5_optimized2014_file3.mv"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.s" "Mur5_optimized2014_file3.s";
connectAttr "Mur5_optimized2014_place2dTexture9.wu" "Mur5_optimized2014_file3.wu"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.wv" "Mur5_optimized2014_file3.wv"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.re" "Mur5_optimized2014_file3.re"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.of" "Mur5_optimized2014_file3.of"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.r" "Mur5_optimized2014_file3.ro"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.n" "Mur5_optimized2014_file3.n";
connectAttr "Mur5_optimized2014_place2dTexture9.vt1" "Mur5_optimized2014_file3.vt1"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.vt2" "Mur5_optimized2014_file3.vt2"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.vt3" "Mur5_optimized2014_file3.vt3"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.vc1" "Mur5_optimized2014_file3.vc1"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.o" "Mur5_optimized2014_file3.uv"
		;
connectAttr "Mur5_optimized2014_place2dTexture9.ofs" "Mur5_optimized2014_file3.fs"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.c" "Mur5_optimized2014_file4.c"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.tf" "Mur5_optimized2014_file4.tf"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.rf" "Mur5_optimized2014_file4.rf"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.mu" "Mur5_optimized2014_file4.mu"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.mv" "Mur5_optimized2014_file4.mv"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.s" "Mur5_optimized2014_file4.s"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.wu" "Mur5_optimized2014_file4.wu"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.wv" "Mur5_optimized2014_file4.wv"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.re" "Mur5_optimized2014_file4.re"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.of" "Mur5_optimized2014_file4.of"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.r" "Mur5_optimized2014_file4.ro"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.n" "Mur5_optimized2014_file4.n"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.vt1" "Mur5_optimized2014_file4.vt1"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.vt2" "Mur5_optimized2014_file4.vt2"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.vt3" "Mur5_optimized2014_file4.vt3"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.vc1" "Mur5_optimized2014_file4.vc1"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.o" "Mur5_optimized2014_file4.uv"
		;
connectAttr "Mur5_optimized2014_place2dTexture10.ofs" "Mur5_optimized2014_file4.fs"
		;
connectAttr "Mur5_optimized2014_file4.oa" "Mur5_optimized2014_bump2d4.bv";
connectAttr "pasted__Mur5_optimized2014_lambert9SG1.msg" "pasted__Mur5_optimized2014_materialInfo4.sg"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.c" "pasted__Mur5_optimized2014_file3.c"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.tf" "pasted__Mur5_optimized2014_file3.tf"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.rf" "pasted__Mur5_optimized2014_file3.rf"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.mu" "pasted__Mur5_optimized2014_file3.mu"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.mv" "pasted__Mur5_optimized2014_file3.mv"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.s" "pasted__Mur5_optimized2014_file3.s"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.wu" "pasted__Mur5_optimized2014_file3.wu"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.wv" "pasted__Mur5_optimized2014_file3.wv"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.re" "pasted__Mur5_optimized2014_file3.re"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.of" "pasted__Mur5_optimized2014_file3.of"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.r" "pasted__Mur5_optimized2014_file3.ro"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.n" "pasted__Mur5_optimized2014_file3.n"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.vt1" "pasted__Mur5_optimized2014_file3.vt1"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.vt2" "pasted__Mur5_optimized2014_file3.vt2"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.vt3" "pasted__Mur5_optimized2014_file3.vt3"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.vc1" "pasted__Mur5_optimized2014_file3.vc1"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.o" "pasted__Mur5_optimized2014_file3.uv"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.ofs" "pasted__Mur5_optimized2014_file3.fs"
		;
connectAttr "pasted__Mur5_optimized2014_file4.oa" "pasted__Mur5_optimized2014_bump2d4.bv"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.c" "pasted__Mur5_optimized2014_file4.c"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.tf" "pasted__Mur5_optimized2014_file4.tf"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.rf" "pasted__Mur5_optimized2014_file4.rf"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.mu" "pasted__Mur5_optimized2014_file4.mu"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.mv" "pasted__Mur5_optimized2014_file4.mv"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.s" "pasted__Mur5_optimized2014_file4.s"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.wu" "pasted__Mur5_optimized2014_file4.wu"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.wv" "pasted__Mur5_optimized2014_file4.wv"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.re" "pasted__Mur5_optimized2014_file4.re"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.of" "pasted__Mur5_optimized2014_file4.of"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.r" "pasted__Mur5_optimized2014_file4.ro"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.n" "pasted__Mur5_optimized2014_file4.n"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.vt1" "pasted__Mur5_optimized2014_file4.vt1"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.vt2" "pasted__Mur5_optimized2014_file4.vt2"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.vt3" "pasted__Mur5_optimized2014_file4.vt3"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.vc1" "pasted__Mur5_optimized2014_file4.vc1"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.o" "pasted__Mur5_optimized2014_file4.uv"
		;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.ofs" "pasted__Mur5_optimized2014_file4.fs"
		;
connectAttr "polySurface34SG.msg" "murBlockMini5_2014_materialInfo3.sg";
connectAttr "murBlockMini5_2014_place2dTexture6.o" "lambert1_Flattened_Diffuse.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture6.ofu" "lambert1_Flattened_Diffuse.ofu"
		;
connectAttr "murBlockMini5_2014_place2dTexture6.ofv" "lambert1_Flattened_Diffuse.ofv"
		;
connectAttr "murBlockMini5_2014_place2dTexture6.rf" "lambert1_Flattened_Diffuse.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture6.reu" "lambert1_Flattened_Diffuse.reu"
		;
connectAttr "murBlockMini5_2014_place2dTexture6.rev" "lambert1_Flattened_Diffuse.rev"
		;
connectAttr "murBlockMini5_2014_place2dTexture6.vt1" "lambert1_Flattened_Diffuse.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture6.vt2" "lambert1_Flattened_Diffuse.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture6.vt3" "lambert1_Flattened_Diffuse.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture6.vc1" "lambert1_Flattened_Diffuse.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture6.ofs" "lambert1_Flattened_Diffuse.fs"
		;
connectAttr "polySurface34SG1.msg" "murBlockMini5_2014_materialInfo4.sg";
connectAttr "lambert1_Flattened_NormalFBXASC032Map.oa" "murBlockMini5_2014_bump2d3.bv"
		;
connectAttr "murBlockMini5_2014_place2dTexture7.o" "lambert1_Flattened_NormalFBXASC032Map.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture7.ofu" "lambert1_Flattened_NormalFBXASC032Map.ofu"
		;
connectAttr "murBlockMini5_2014_place2dTexture7.ofv" "lambert1_Flattened_NormalFBXASC032Map.ofv"
		;
connectAttr "murBlockMini5_2014_place2dTexture7.rf" "lambert1_Flattened_NormalFBXASC032Map.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture7.reu" "lambert1_Flattened_NormalFBXASC032Map.reu"
		;
connectAttr "murBlockMini5_2014_place2dTexture7.rev" "lambert1_Flattened_NormalFBXASC032Map.rev"
		;
connectAttr "murBlockMini5_2014_place2dTexture7.vt1" "lambert1_Flattened_NormalFBXASC032Map.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture7.vt2" "lambert1_Flattened_NormalFBXASC032Map.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture7.vt3" "lambert1_Flattened_NormalFBXASC032Map.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture7.vc1" "lambert1_Flattened_NormalFBXASC032Map.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture7.ofs" "lambert1_Flattened_NormalFBXASC032Map.fs"
		;
connectAttr "murBlockMini5_2014_lambert12_Flattened_Diffuse.oc" "murBlockMini5_2014_lambert12.c"
		;
connectAttr "murBlockMini5_2014_bump2d4.o" "murBlockMini5_2014_lambert12.n";
connectAttr "murBlockMini5_2014_ReflectionMap.oc" "murBlockMini5_2014_lambert12.rc"
		;
connectAttr "murBlockMini5_2014_lambert12.oc" "polySurface34SG2.ss";
connectAttr "polySurface34SG2.msg" "murBlockMini5_2014_materialInfo5.sg";
connectAttr "murBlockMini5_2014_lambert12.msg" "murBlockMini5_2014_materialInfo5.m"
		;
connectAttr "murBlockMini5_2014_lambert12_Flattened_Diffuse.msg" "murBlockMini5_2014_materialInfo5.t"
		 -na;
connectAttr "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map.oa" "murBlockMini5_2014_bump2d4.bv"
		;
connectAttr "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.oc" "murBlockMini5_2014_lambert8.c"
		;
connectAttr "Mur5_optimized2014_5_bump2d1.o" "murBlockMini5_2014_lambert8.n";
connectAttr "Mur5_optimized2014_5_ReflectionMap.oc" "murBlockMini5_2014_lambert8.rc"
		;
connectAttr "murBlockMini5_2014_lambert8.oc" "Mur5_optimized2014_5_polySurface33SG.ss"
		;
connectAttr "Mur5_optimized2014_5_polySurface33SG.msg" "Mur5_optimized2014_5_materialInfo1.sg"
		;
connectAttr "murBlockMini5_2014_lambert8.msg" "Mur5_optimized2014_5_materialInfo1.m"
		;
connectAttr "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.msg" "Mur5_optimized2014_5_materialInfo1.t"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture1.o" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture1.ofu" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture1.ofv" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture1.rf" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture1.reu" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture1.rev" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture1.vt1" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture1.vt2" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture1.vt3" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture1.vc1" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture1.ofs" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "Mur5_optimized2014_5_bump2d1.bv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture2.o" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture2.ofu" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture2.ofv" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture2.rf" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture2.reu" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture2.rev" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture2.vt1" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture2.vt2" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture2.vt3" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture2.vc1" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture2.ofs" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture3.o" "Mur5_optimized2014_5_ReflectionMap.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture3.ofu" "Mur5_optimized2014_5_ReflectionMap.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture3.ofv" "Mur5_optimized2014_5_ReflectionMap.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture3.rf" "Mur5_optimized2014_5_ReflectionMap.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture3.reu" "Mur5_optimized2014_5_ReflectionMap.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture3.rev" "Mur5_optimized2014_5_ReflectionMap.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture3.vt1" "Mur5_optimized2014_5_ReflectionMap.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture3.vt2" "Mur5_optimized2014_5_ReflectionMap.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture3.vt3" "Mur5_optimized2014_5_ReflectionMap.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture3.vc1" "Mur5_optimized2014_5_ReflectionMap.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture3.ofs" "Mur5_optimized2014_5_ReflectionMap.fs"
		;
connectAttr "Mur5_optimized2014_5_file1.oc" "murBlockMini5_2014_lambert9.c";
connectAttr "Mur5_optimized2014_5_file1.ot" "murBlockMini5_2014_lambert9.it";
connectAttr "Mur5_optimized2014_5_bump2d2.o" "murBlockMini5_2014_lambert9.n";
connectAttr "murBlockMini5_2014_lambert9.oc" "Mur5_optimized2014_5_lambert9SG.ss"
		;
connectAttr "Mur5_optimized2014_5_lambert9SG.msg" "Mur5_optimized2014_5_materialInfo2.sg"
		;
connectAttr "murBlockMini5_2014_lambert9.msg" "Mur5_optimized2014_5_materialInfo2.m"
		;
connectAttr "Mur5_optimized2014_5_file1.msg" "Mur5_optimized2014_5_materialInfo2.t"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture4.c" "Mur5_optimized2014_5_file1.c"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.tf" "Mur5_optimized2014_5_file1.tf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.rf" "Mur5_optimized2014_5_file1.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.mu" "Mur5_optimized2014_5_file1.mu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.mv" "Mur5_optimized2014_5_file1.mv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.s" "Mur5_optimized2014_5_file1.s"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.wu" "Mur5_optimized2014_5_file1.wu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.wv" "Mur5_optimized2014_5_file1.wv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.re" "Mur5_optimized2014_5_file1.re"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.of" "Mur5_optimized2014_5_file1.of"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.r" "Mur5_optimized2014_5_file1.ro"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.n" "Mur5_optimized2014_5_file1.n"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.vt1" "Mur5_optimized2014_5_file1.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.vt2" "Mur5_optimized2014_5_file1.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.vt3" "Mur5_optimized2014_5_file1.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.vc1" "Mur5_optimized2014_5_file1.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.o" "Mur5_optimized2014_5_file1.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture4.ofs" "Mur5_optimized2014_5_file1.fs"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.c" "Mur5_optimized2014_5_file2.c"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.tf" "Mur5_optimized2014_5_file2.tf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.rf" "Mur5_optimized2014_5_file2.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.mu" "Mur5_optimized2014_5_file2.mu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.mv" "Mur5_optimized2014_5_file2.mv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.s" "Mur5_optimized2014_5_file2.s"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.wu" "Mur5_optimized2014_5_file2.wu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.wv" "Mur5_optimized2014_5_file2.wv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.re" "Mur5_optimized2014_5_file2.re"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.of" "Mur5_optimized2014_5_file2.of"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.r" "Mur5_optimized2014_5_file2.ro"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.n" "Mur5_optimized2014_5_file2.n"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.vt1" "Mur5_optimized2014_5_file2.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.vt2" "Mur5_optimized2014_5_file2.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.vt3" "Mur5_optimized2014_5_file2.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.vc1" "Mur5_optimized2014_5_file2.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.o" "Mur5_optimized2014_5_file2.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture5.ofs" "Mur5_optimized2014_5_file2.fs"
		;
connectAttr "Mur5_optimized2014_5_file2.oa" "Mur5_optimized2014_5_bump2d2.bv";
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.oc" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8.c"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_bump2d1.o" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8.n"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap.oc" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8.rc"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_lambert8.oc" "murBlockMini5_2014_Mur5_optimized2014_2_polySurface33SG.ss"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_polySurface33SG.msg" "murBlockMini5_2014_Mur5_optimized2014_2_materialInfo1.sg"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_lambert8.msg" "murBlockMini5_2014_Mur5_optimized2014_2_materialInfo1.m"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" "murBlockMini5_2014_Mur5_optimized2014_2_materialInfo1.t"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture1.o" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture1.ofu" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture1.ofv" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture1.rf" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture1.reu" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture1.rev" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture1.vt1" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture1.vt2" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture1.vt3" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture1.vc1" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture1.ofs" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murBlockMini5_2014_Mur5_optimized2014_2_bump2d1.bv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture2.o" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture2.ofu" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture2.ofv" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture2.rf" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture2.reu" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture2.rev" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture2.vt1" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture2.vt2" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture2.vt3" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture2.vc1" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture2.ofs" "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture3.o" "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap.uv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture3.ofu" "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap.ofu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture3.ofv" "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap.ofv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture3.rf" "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap.rf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture3.reu" "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap.reu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture3.rev" "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap.rev"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture3.vt1" "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap.vt1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture3.vt2" "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap.vt2"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture3.vt3" "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap.vt3"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture3.vc1" "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap.vc1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture3.ofs" "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap.fs"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_file1.oc" "murBlockMini5_2014_Mur5_optimized2014_2_lambert9.c"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_file1.ot" "murBlockMini5_2014_Mur5_optimized2014_2_lambert9.it"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_bump2d2.o" "murBlockMini5_2014_Mur5_optimized2014_2_lambert9.n"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_lambert9.oc" "murBlockMini5_2014_Mur5_optimized2014_2_lambert9SG.ss"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_lambert9SG.msg" "murBlockMini5_2014_Mur5_optimized2014_2_materialInfo2.sg"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_lambert9.msg" "murBlockMini5_2014_Mur5_optimized2014_2_materialInfo2.m"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_file1.msg" "murBlockMini5_2014_Mur5_optimized2014_2_materialInfo2.t"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.c" "murBlockMini5_2014_Mur5_optimized2014_2_file1.c"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.tf" "murBlockMini5_2014_Mur5_optimized2014_2_file1.tf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.rf" "murBlockMini5_2014_Mur5_optimized2014_2_file1.rf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.mu" "murBlockMini5_2014_Mur5_optimized2014_2_file1.mu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.mv" "murBlockMini5_2014_Mur5_optimized2014_2_file1.mv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.s" "murBlockMini5_2014_Mur5_optimized2014_2_file1.s"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.wu" "murBlockMini5_2014_Mur5_optimized2014_2_file1.wu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.wv" "murBlockMini5_2014_Mur5_optimized2014_2_file1.wv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.re" "murBlockMini5_2014_Mur5_optimized2014_2_file1.re"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.of" "murBlockMini5_2014_Mur5_optimized2014_2_file1.of"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.r" "murBlockMini5_2014_Mur5_optimized2014_2_file1.ro"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.n" "murBlockMini5_2014_Mur5_optimized2014_2_file1.n"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.vt1" "murBlockMini5_2014_Mur5_optimized2014_2_file1.vt1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.vt2" "murBlockMini5_2014_Mur5_optimized2014_2_file1.vt2"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.vt3" "murBlockMini5_2014_Mur5_optimized2014_2_file1.vt3"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.vc1" "murBlockMini5_2014_Mur5_optimized2014_2_file1.vc1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.o" "murBlockMini5_2014_Mur5_optimized2014_2_file1.uv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.ofs" "murBlockMini5_2014_Mur5_optimized2014_2_file1.fs"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.c" "murBlockMini5_2014_Mur5_optimized2014_2_file2.c"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.tf" "murBlockMini5_2014_Mur5_optimized2014_2_file2.tf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.rf" "murBlockMini5_2014_Mur5_optimized2014_2_file2.rf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.mu" "murBlockMini5_2014_Mur5_optimized2014_2_file2.mu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.mv" "murBlockMini5_2014_Mur5_optimized2014_2_file2.mv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.s" "murBlockMini5_2014_Mur5_optimized2014_2_file2.s"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.wu" "murBlockMini5_2014_Mur5_optimized2014_2_file2.wu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.wv" "murBlockMini5_2014_Mur5_optimized2014_2_file2.wv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.re" "murBlockMini5_2014_Mur5_optimized2014_2_file2.re"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.of" "murBlockMini5_2014_Mur5_optimized2014_2_file2.of"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.r" "murBlockMini5_2014_Mur5_optimized2014_2_file2.ro"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.n" "murBlockMini5_2014_Mur5_optimized2014_2_file2.n"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.vt1" "murBlockMini5_2014_Mur5_optimized2014_2_file2.vt1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.vt2" "murBlockMini5_2014_Mur5_optimized2014_2_file2.vt2"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.vt3" "murBlockMini5_2014_Mur5_optimized2014_2_file2.vt3"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.vc1" "murBlockMini5_2014_Mur5_optimized2014_2_file2.vc1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.o" "murBlockMini5_2014_Mur5_optimized2014_2_file2.uv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.ofs" "murBlockMini5_2014_Mur5_optimized2014_2_file2.fs"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_file2.oa" "murBlockMini5_2014_Mur5_optimized2014_2_bump2d2.bv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.oc" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8.c"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_bump2d1.o" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8.n"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.oc" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8.rc"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_lambert8.oc" "murBlockMini5_2014_Mur5_optimized2014_4_polySurface33SG.ss"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_polySurface33SG.msg" "murBlockMini5_2014_Mur5_optimized2014_4_materialInfo1.sg"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_lambert8.msg" "murBlockMini5_2014_Mur5_optimized2014_4_materialInfo1.m"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" "murBlockMini5_2014_Mur5_optimized2014_4_materialInfo1.t"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture1.o" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture1.ofu" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture1.ofv" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture1.rf" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture1.reu" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture1.rev" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture1.vt1" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture1.vt2" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture1.vt3" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture1.vc1" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture1.ofs" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murBlockMini5_2014_Mur5_optimized2014_4_bump2d1.bv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture2.o" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture2.ofu" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture2.ofv" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture2.rf" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture2.reu" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture2.rev" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture2.vt1" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture2.vt2" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture2.vt3" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture2.vc1" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture2.ofs" "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture3.o" "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.uv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture3.ofu" "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.ofu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture3.ofv" "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.ofv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture3.rf" "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.rf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture3.reu" "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.reu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture3.rev" "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.rev"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture3.vt1" "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.vt1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture3.vt2" "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.vt2"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture3.vt3" "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.vt3"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture3.vc1" "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.vc1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture3.ofs" "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.fs"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_file1.oc" "murBlockMini5_2014_Mur5_optimized2014_4_lambert9.c"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_file1.ot" "murBlockMini5_2014_Mur5_optimized2014_4_lambert9.it"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_bump2d2.o" "murBlockMini5_2014_Mur5_optimized2014_4_lambert9.n"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_lambert9.oc" "murBlockMini5_2014_Mur5_optimized2014_4_lambert9SG.ss"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_lambert9SG.msg" "murBlockMini5_2014_Mur5_optimized2014_4_materialInfo2.sg"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_lambert9.msg" "murBlockMini5_2014_Mur5_optimized2014_4_materialInfo2.m"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_file1.msg" "murBlockMini5_2014_Mur5_optimized2014_4_materialInfo2.t"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.c" "murBlockMini5_2014_Mur5_optimized2014_4_file1.c"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.tf" "murBlockMini5_2014_Mur5_optimized2014_4_file1.tf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.rf" "murBlockMini5_2014_Mur5_optimized2014_4_file1.rf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.mu" "murBlockMini5_2014_Mur5_optimized2014_4_file1.mu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.mv" "murBlockMini5_2014_Mur5_optimized2014_4_file1.mv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.s" "murBlockMini5_2014_Mur5_optimized2014_4_file1.s"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.wu" "murBlockMini5_2014_Mur5_optimized2014_4_file1.wu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.wv" "murBlockMini5_2014_Mur5_optimized2014_4_file1.wv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.re" "murBlockMini5_2014_Mur5_optimized2014_4_file1.re"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.of" "murBlockMini5_2014_Mur5_optimized2014_4_file1.of"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.r" "murBlockMini5_2014_Mur5_optimized2014_4_file1.ro"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.n" "murBlockMini5_2014_Mur5_optimized2014_4_file1.n"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.vt1" "murBlockMini5_2014_Mur5_optimized2014_4_file1.vt1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.vt2" "murBlockMini5_2014_Mur5_optimized2014_4_file1.vt2"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.vt3" "murBlockMini5_2014_Mur5_optimized2014_4_file1.vt3"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.vc1" "murBlockMini5_2014_Mur5_optimized2014_4_file1.vc1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.o" "murBlockMini5_2014_Mur5_optimized2014_4_file1.uv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.ofs" "murBlockMini5_2014_Mur5_optimized2014_4_file1.fs"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.c" "murBlockMini5_2014_Mur5_optimized2014_4_file2.c"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.tf" "murBlockMini5_2014_Mur5_optimized2014_4_file2.tf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.rf" "murBlockMini5_2014_Mur5_optimized2014_4_file2.rf"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.mu" "murBlockMini5_2014_Mur5_optimized2014_4_file2.mu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.mv" "murBlockMini5_2014_Mur5_optimized2014_4_file2.mv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.s" "murBlockMini5_2014_Mur5_optimized2014_4_file2.s"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.wu" "murBlockMini5_2014_Mur5_optimized2014_4_file2.wu"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.wv" "murBlockMini5_2014_Mur5_optimized2014_4_file2.wv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.re" "murBlockMini5_2014_Mur5_optimized2014_4_file2.re"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.of" "murBlockMini5_2014_Mur5_optimized2014_4_file2.of"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.r" "murBlockMini5_2014_Mur5_optimized2014_4_file2.ro"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.n" "murBlockMini5_2014_Mur5_optimized2014_4_file2.n"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.vt1" "murBlockMini5_2014_Mur5_optimized2014_4_file2.vt1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.vt2" "murBlockMini5_2014_Mur5_optimized2014_4_file2.vt2"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.vt3" "murBlockMini5_2014_Mur5_optimized2014_4_file2.vt3"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.vc1" "murBlockMini5_2014_Mur5_optimized2014_4_file2.vc1"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.o" "murBlockMini5_2014_Mur5_optimized2014_4_file2.uv"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.ofs" "murBlockMini5_2014_Mur5_optimized2014_4_file2.fs"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_file2.oa" "murBlockMini5_2014_Mur5_optimized2014_4_bump2d2.bv"
		;
connectAttr "murBlockMini5_2014_lambert9_Flattened_Diffuse.oc" "murBlockMini5_2014_lambert10.c"
		;
connectAttr "Mur5_optimized2014_5_bump2d3.o" "murBlockMini5_2014_lambert10.n";
connectAttr "murBlockMini5_2014_lambert9_Flattened_Opacity.ot" "murBlockMini5_2014_lambert10.it"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.oc" "murBlockMini5_2014_lambert10.rc"
		;
connectAttr "murBlockMini5_2014_lambert10.oc" "murBlockMini5_2014_wallSG.ss";
connectAttr "murBlockMini5_2014_wallSG.msg" "Mur5_optimized2014_5_materialInfo3.sg"
		;
connectAttr "murBlockMini5_2014_lambert10.msg" "Mur5_optimized2014_5_materialInfo3.m"
		;
connectAttr "murBlockMini5_2014_lambert9_Flattened_Diffuse.msg" "Mur5_optimized2014_5_materialInfo3.t"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture6.o" "murBlockMini5_2014_lambert9_Flattened_Diffuse.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture6.ofu" "murBlockMini5_2014_lambert9_Flattened_Diffuse.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture6.ofv" "murBlockMini5_2014_lambert9_Flattened_Diffuse.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture6.rf" "murBlockMini5_2014_lambert9_Flattened_Diffuse.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture6.reu" "murBlockMini5_2014_lambert9_Flattened_Diffuse.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture6.rev" "murBlockMini5_2014_lambert9_Flattened_Diffuse.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture6.vt1" "murBlockMini5_2014_lambert9_Flattened_Diffuse.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture6.vt2" "murBlockMini5_2014_lambert9_Flattened_Diffuse.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture6.vt3" "murBlockMini5_2014_lambert9_Flattened_Diffuse.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture6.vc1" "murBlockMini5_2014_lambert9_Flattened_Diffuse.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture6.ofs" "murBlockMini5_2014_lambert9_Flattened_Diffuse.fs"
		;
connectAttr "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map.oa" "Mur5_optimized2014_5_bump2d3.bv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture7.o" "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture7.ofu" "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture7.ofv" "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture7.rf" "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture7.reu" "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture7.rev" "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture7.vt1" "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture7.vt2" "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture7.vt3" "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture7.vc1" "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture7.ofs" "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murBlockMini5_2014_place2dTexture8.o" "murBlockMini5_2014_lambert9_Flattened_Opacity.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture8.ofu" "murBlockMini5_2014_lambert9_Flattened_Opacity.ofu"
		;
connectAttr "murBlockMini5_2014_place2dTexture8.ofv" "murBlockMini5_2014_lambert9_Flattened_Opacity.ofv"
		;
connectAttr "murBlockMini5_2014_place2dTexture8.rf" "murBlockMini5_2014_lambert9_Flattened_Opacity.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture8.reu" "murBlockMini5_2014_lambert9_Flattened_Opacity.reu"
		;
connectAttr "murBlockMini5_2014_place2dTexture8.rev" "murBlockMini5_2014_lambert9_Flattened_Opacity.rev"
		;
connectAttr "murBlockMini5_2014_place2dTexture8.vt1" "murBlockMini5_2014_lambert9_Flattened_Opacity.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture8.vt2" "murBlockMini5_2014_lambert9_Flattened_Opacity.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture8.vt3" "murBlockMini5_2014_lambert9_Flattened_Opacity.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture8.vc1" "murBlockMini5_2014_lambert9_Flattened_Opacity.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture8.ofs" "murBlockMini5_2014_lambert9_Flattened_Opacity.fs"
		;
connectAttr "murBlockMini5_2014_lambert11_Flattened_Diffuse.oc" "murBlockMini5_2014_lambert11.c"
		;
connectAttr "Mur5_optimized2014_5_bump2d4.o" "murBlockMini5_2014_lambert11.n";
connectAttr "murBlockMini5_2014_lambert11_Flattened_Opacity.ot" "murBlockMini5_2014_lambert11.it"
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.oc" "murBlockMini5_2014_lambert11.rc"
		;
connectAttr "murBlockMini5_2014_lambert11.oc" "murBlockMini5_2014_wallSG1.ss";
connectAttr "murBlockMini5_2014_wallSG1.msg" "Mur5_optimized2014_5_materialInfo4.sg"
		;
connectAttr "murBlockMini5_2014_lambert11.msg" "Mur5_optimized2014_5_materialInfo4.m"
		;
connectAttr "murBlockMini5_2014_lambert11_Flattened_Diffuse.msg" "Mur5_optimized2014_5_materialInfo4.t"
		 -na;
connectAttr "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map.oa" "Mur5_optimized2014_5_bump2d4.bv"
		;
connectAttr "murBlockMini5_2014_place2dTexture9.o" "murBlockMini5_2014_lambert11_Flattened_Diffuse.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture9.ofu" "murBlockMini5_2014_lambert11_Flattened_Diffuse.ofu"
		;
connectAttr "murBlockMini5_2014_place2dTexture9.ofv" "murBlockMini5_2014_lambert11_Flattened_Diffuse.ofv"
		;
connectAttr "murBlockMini5_2014_place2dTexture9.rf" "murBlockMini5_2014_lambert11_Flattened_Diffuse.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture9.reu" "murBlockMini5_2014_lambert11_Flattened_Diffuse.reu"
		;
connectAttr "murBlockMini5_2014_place2dTexture9.rev" "murBlockMini5_2014_lambert11_Flattened_Diffuse.rev"
		;
connectAttr "murBlockMini5_2014_place2dTexture9.vt1" "murBlockMini5_2014_lambert11_Flattened_Diffuse.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture9.vt2" "murBlockMini5_2014_lambert11_Flattened_Diffuse.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture9.vt3" "murBlockMini5_2014_lambert11_Flattened_Diffuse.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture9.vc1" "murBlockMini5_2014_lambert11_Flattened_Diffuse.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture9.ofs" "murBlockMini5_2014_lambert11_Flattened_Diffuse.fs"
		;
connectAttr "murBlockMini5_2014_place2dTexture10.o" "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture10.ofu" "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "murBlockMini5_2014_place2dTexture10.ofv" "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "murBlockMini5_2014_place2dTexture10.rf" "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture10.reu" "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "murBlockMini5_2014_place2dTexture10.rev" "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "murBlockMini5_2014_place2dTexture10.vt1" "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture10.vt2" "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture10.vt3" "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture10.vc1" "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture10.ofs" "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murBlockMini5_2014_place2dTexture11.o" "murBlockMini5_2014_lambert11_Flattened_Opacity.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture11.ofu" "murBlockMini5_2014_lambert11_Flattened_Opacity.ofu"
		;
connectAttr "murBlockMini5_2014_place2dTexture11.ofv" "murBlockMini5_2014_lambert11_Flattened_Opacity.ofv"
		;
connectAttr "murBlockMini5_2014_place2dTexture11.rf" "murBlockMini5_2014_lambert11_Flattened_Opacity.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture11.reu" "murBlockMini5_2014_lambert11_Flattened_Opacity.reu"
		;
connectAttr "murBlockMini5_2014_place2dTexture11.rev" "murBlockMini5_2014_lambert11_Flattened_Opacity.rev"
		;
connectAttr "murBlockMini5_2014_place2dTexture11.vt1" "murBlockMini5_2014_lambert11_Flattened_Opacity.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture11.vt2" "murBlockMini5_2014_lambert11_Flattened_Opacity.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture11.vt3" "murBlockMini5_2014_lambert11_Flattened_Opacity.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture11.vc1" "murBlockMini5_2014_lambert11_Flattened_Opacity.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture11.ofs" "murBlockMini5_2014_lambert11_Flattened_Opacity.fs"
		;
connectAttr "murBlockMini1_2014_polySurface33SG.msg" "murBlockMini1_2014_materialInfo1.sg"
		;
connectAttr "murBlockMini1_2014_place2dTexture1.o" "murBlockMini1_2014_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murBlockMini1_2014_place2dTexture1.ofu" "murBlockMini1_2014_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murBlockMini1_2014_place2dTexture1.ofv" "murBlockMini1_2014_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murBlockMini1_2014_place2dTexture1.rf" "murBlockMini1_2014_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murBlockMini1_2014_place2dTexture1.reu" "murBlockMini1_2014_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murBlockMini1_2014_place2dTexture1.rev" "murBlockMini1_2014_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murBlockMini1_2014_place2dTexture1.vt1" "murBlockMini1_2014_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murBlockMini1_2014_place2dTexture1.vt2" "murBlockMini1_2014_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murBlockMini1_2014_place2dTexture1.vt3" "murBlockMini1_2014_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murBlockMini1_2014_place2dTexture1.vc1" "murBlockMini1_2014_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murBlockMini1_2014_place2dTexture1.ofs" "murBlockMini1_2014_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murBlockMini1_2014_bump2d1.bv"
		;
connectAttr "murBlockMini1_2014_place2dTexture2.o" "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murBlockMini1_2014_place2dTexture2.ofu" "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murBlockMini1_2014_place2dTexture2.ofv" "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murBlockMini1_2014_place2dTexture2.rf" "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murBlockMini1_2014_place2dTexture2.reu" "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murBlockMini1_2014_place2dTexture2.rev" "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murBlockMini1_2014_place2dTexture2.vt1" "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murBlockMini1_2014_place2dTexture2.vt2" "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murBlockMini1_2014_place2dTexture2.vt3" "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murBlockMini1_2014_place2dTexture2.vc1" "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murBlockMini1_2014_place2dTexture2.ofs" "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murBlockMini1_2014_place2dTexture3.o" "murBlockMini1_2014_ReflectionMap.uv"
		;
connectAttr "murBlockMini1_2014_place2dTexture3.ofu" "murBlockMini1_2014_ReflectionMap.ofu"
		;
connectAttr "murBlockMini1_2014_place2dTexture3.ofv" "murBlockMini1_2014_ReflectionMap.ofv"
		;
connectAttr "murBlockMini1_2014_place2dTexture3.rf" "murBlockMini1_2014_ReflectionMap.rf"
		;
connectAttr "murBlockMini1_2014_place2dTexture3.reu" "murBlockMini1_2014_ReflectionMap.reu"
		;
connectAttr "murBlockMini1_2014_place2dTexture3.rev" "murBlockMini1_2014_ReflectionMap.rev"
		;
connectAttr "murBlockMini1_2014_place2dTexture3.vt1" "murBlockMini1_2014_ReflectionMap.vt1"
		;
connectAttr "murBlockMini1_2014_place2dTexture3.vt2" "murBlockMini1_2014_ReflectionMap.vt2"
		;
connectAttr "murBlockMini1_2014_place2dTexture3.vt3" "murBlockMini1_2014_ReflectionMap.vt3"
		;
connectAttr "murBlockMini1_2014_place2dTexture3.vc1" "murBlockMini1_2014_ReflectionMap.vc1"
		;
connectAttr "murBlockMini1_2014_place2dTexture3.ofs" "murBlockMini1_2014_ReflectionMap.fs"
		;
connectAttr "murBlockMini1_2014_lambert9SG.msg" "murBlockMini1_2014_materialInfo2.sg"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.c" "murBlockMini1_2014_file1.c";
connectAttr "murBlockMini1_2014_place2dTexture4.tf" "murBlockMini1_2014_file1.tf"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.rf" "murBlockMini1_2014_file1.rf"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.mu" "murBlockMini1_2014_file1.mu"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.mv" "murBlockMini1_2014_file1.mv"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.s" "murBlockMini1_2014_file1.s";
connectAttr "murBlockMini1_2014_place2dTexture4.wu" "murBlockMini1_2014_file1.wu"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.wv" "murBlockMini1_2014_file1.wv"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.re" "murBlockMini1_2014_file1.re"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.of" "murBlockMini1_2014_file1.of"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.r" "murBlockMini1_2014_file1.ro"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.n" "murBlockMini1_2014_file1.n";
connectAttr "murBlockMini1_2014_place2dTexture4.vt1" "murBlockMini1_2014_file1.vt1"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.vt2" "murBlockMini1_2014_file1.vt2"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.vt3" "murBlockMini1_2014_file1.vt3"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.vc1" "murBlockMini1_2014_file1.vc1"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.o" "murBlockMini1_2014_file1.uv"
		;
connectAttr "murBlockMini1_2014_place2dTexture4.ofs" "murBlockMini1_2014_file1.fs"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.c" "murBlockMini1_2014_file2.c";
connectAttr "murBlockMini1_2014_place2dTexture5.tf" "murBlockMini1_2014_file2.tf"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.rf" "murBlockMini1_2014_file2.rf"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.mu" "murBlockMini1_2014_file2.mu"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.mv" "murBlockMini1_2014_file2.mv"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.s" "murBlockMini1_2014_file2.s";
connectAttr "murBlockMini1_2014_place2dTexture5.wu" "murBlockMini1_2014_file2.wu"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.wv" "murBlockMini1_2014_file2.wv"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.re" "murBlockMini1_2014_file2.re"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.of" "murBlockMini1_2014_file2.of"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.r" "murBlockMini1_2014_file2.ro"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.n" "murBlockMini1_2014_file2.n";
connectAttr "murBlockMini1_2014_place2dTexture5.vt1" "murBlockMini1_2014_file2.vt1"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.vt2" "murBlockMini1_2014_file2.vt2"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.vt3" "murBlockMini1_2014_file2.vt3"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.vc1" "murBlockMini1_2014_file2.vc1"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.o" "murBlockMini1_2014_file2.uv"
		;
connectAttr "murBlockMini1_2014_place2dTexture5.ofs" "murBlockMini1_2014_file2.fs"
		;
connectAttr "murBlockMini1_2014_file2.oa" "murBlockMini1_2014_bump2d2.bv";
connectAttr "murBlockMini1_2014_Mur5_optimized2014_polySurface33SG.msg" "murBlockMini1_2014_Mur5_optimized2014_materialInfo1.sg"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture1.o" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture1.ofu" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture1.ofv" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture1.rf" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture1.reu" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture1.rev" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture1.vt1" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture1.vt2" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture1.vt3" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture1.vc1" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture1.ofs" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murBlockMini1_2014_Mur5_optimized2014_bump2d1.bv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture2.o" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture2.ofu" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture2.ofv" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture2.rf" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture2.reu" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture2.rev" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture2.vt1" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture2.vt2" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture2.vt3" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture2.vc1" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture2.ofs" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture3.o" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture3.ofu" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture3.ofv" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture3.rf" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture3.reu" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture3.rev" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture3.vt1" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture3.vt2" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture3.vt3" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture3.vc1" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture3.ofs" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_lambert9SG.msg" "murBlockMini1_2014_Mur5_optimized2014_materialInfo2.sg"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.c" "murBlockMini1_2014_Mur5_optimized2014_file1.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.tf" "murBlockMini1_2014_Mur5_optimized2014_file1.tf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.rf" "murBlockMini1_2014_Mur5_optimized2014_file1.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.mu" "murBlockMini1_2014_Mur5_optimized2014_file1.mu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.mv" "murBlockMini1_2014_Mur5_optimized2014_file1.mv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.s" "murBlockMini1_2014_Mur5_optimized2014_file1.s"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.wu" "murBlockMini1_2014_Mur5_optimized2014_file1.wu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.wv" "murBlockMini1_2014_Mur5_optimized2014_file1.wv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.re" "murBlockMini1_2014_Mur5_optimized2014_file1.re"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.of" "murBlockMini1_2014_Mur5_optimized2014_file1.of"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.r" "murBlockMini1_2014_Mur5_optimized2014_file1.ro"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.n" "murBlockMini1_2014_Mur5_optimized2014_file1.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.vt1" "murBlockMini1_2014_Mur5_optimized2014_file1.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.vt2" "murBlockMini1_2014_Mur5_optimized2014_file1.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.vt3" "murBlockMini1_2014_Mur5_optimized2014_file1.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.vc1" "murBlockMini1_2014_Mur5_optimized2014_file1.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.o" "murBlockMini1_2014_Mur5_optimized2014_file1.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.ofs" "murBlockMini1_2014_Mur5_optimized2014_file1.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.c" "murBlockMini1_2014_Mur5_optimized2014_file2.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.tf" "murBlockMini1_2014_Mur5_optimized2014_file2.tf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.rf" "murBlockMini1_2014_Mur5_optimized2014_file2.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.mu" "murBlockMini1_2014_Mur5_optimized2014_file2.mu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.mv" "murBlockMini1_2014_Mur5_optimized2014_file2.mv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.s" "murBlockMini1_2014_Mur5_optimized2014_file2.s"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.wu" "murBlockMini1_2014_Mur5_optimized2014_file2.wu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.wv" "murBlockMini1_2014_Mur5_optimized2014_file2.wv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.re" "murBlockMini1_2014_Mur5_optimized2014_file2.re"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.of" "murBlockMini1_2014_Mur5_optimized2014_file2.of"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.r" "murBlockMini1_2014_Mur5_optimized2014_file2.ro"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.n" "murBlockMini1_2014_Mur5_optimized2014_file2.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.vt1" "murBlockMini1_2014_Mur5_optimized2014_file2.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.vt2" "murBlockMini1_2014_Mur5_optimized2014_file2.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.vt3" "murBlockMini1_2014_Mur5_optimized2014_file2.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.vc1" "murBlockMini1_2014_Mur5_optimized2014_file2.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.o" "murBlockMini1_2014_Mur5_optimized2014_file2.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.ofs" "murBlockMini1_2014_Mur5_optimized2014_file2.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_file2.oa" "murBlockMini1_2014_Mur5_optimized2014_bump2d2.bv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_polySurface33SG1.msg" "murBlockMini1_2014_Mur5_optimized2014_materialInfo3.sg"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture6.o" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture6.ofu" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture6.ofv" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture6.rf" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture6.reu" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture6.rev" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture6.vt1" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture6.vt2" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture6.vt3" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture6.vc1" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture6.ofs" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.oa" "murBlockMini1_2014_Mur5_optimized2014_bump2d3.bv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture7.o" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture7.ofu" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture7.ofv" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture7.rf" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture7.reu" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture7.rev" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture7.vt1" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture7.vt2" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture7.vt3" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture7.vc1" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture7.ofs" "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture8.o" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap1.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture8.ofu" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap1.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture8.ofv" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap1.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture8.rf" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap1.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture8.reu" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap1.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture8.rev" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap1.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture8.vt1" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap1.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture8.vt2" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap1.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture8.vt3" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap1.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture8.vc1" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap1.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture8.ofs" "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap1.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_lambert9SG1.msg" "murBlockMini1_2014_Mur5_optimized2014_materialInfo4.sg"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.c" "murBlockMini1_2014_Mur5_optimized2014_file3.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.tf" "murBlockMini1_2014_Mur5_optimized2014_file3.tf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.rf" "murBlockMini1_2014_Mur5_optimized2014_file3.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.mu" "murBlockMini1_2014_Mur5_optimized2014_file3.mu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.mv" "murBlockMini1_2014_Mur5_optimized2014_file3.mv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.s" "murBlockMini1_2014_Mur5_optimized2014_file3.s"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.wu" "murBlockMini1_2014_Mur5_optimized2014_file3.wu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.wv" "murBlockMini1_2014_Mur5_optimized2014_file3.wv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.re" "murBlockMini1_2014_Mur5_optimized2014_file3.re"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.of" "murBlockMini1_2014_Mur5_optimized2014_file3.of"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.r" "murBlockMini1_2014_Mur5_optimized2014_file3.ro"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.n" "murBlockMini1_2014_Mur5_optimized2014_file3.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.vt1" "murBlockMini1_2014_Mur5_optimized2014_file3.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.vt2" "murBlockMini1_2014_Mur5_optimized2014_file3.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.vt3" "murBlockMini1_2014_Mur5_optimized2014_file3.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.vc1" "murBlockMini1_2014_Mur5_optimized2014_file3.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.o" "murBlockMini1_2014_Mur5_optimized2014_file3.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.ofs" "murBlockMini1_2014_Mur5_optimized2014_file3.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.c" "murBlockMini1_2014_Mur5_optimized2014_file4.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.tf" "murBlockMini1_2014_Mur5_optimized2014_file4.tf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.rf" "murBlockMini1_2014_Mur5_optimized2014_file4.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.mu" "murBlockMini1_2014_Mur5_optimized2014_file4.mu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.mv" "murBlockMini1_2014_Mur5_optimized2014_file4.mv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.s" "murBlockMini1_2014_Mur5_optimized2014_file4.s"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.wu" "murBlockMini1_2014_Mur5_optimized2014_file4.wu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.wv" "murBlockMini1_2014_Mur5_optimized2014_file4.wv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.re" "murBlockMini1_2014_Mur5_optimized2014_file4.re"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.of" "murBlockMini1_2014_Mur5_optimized2014_file4.of"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.r" "murBlockMini1_2014_Mur5_optimized2014_file4.ro"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.n" "murBlockMini1_2014_Mur5_optimized2014_file4.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.vt1" "murBlockMini1_2014_Mur5_optimized2014_file4.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.vt2" "murBlockMini1_2014_Mur5_optimized2014_file4.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.vt3" "murBlockMini1_2014_Mur5_optimized2014_file4.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.vc1" "murBlockMini1_2014_Mur5_optimized2014_file4.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.o" "murBlockMini1_2014_Mur5_optimized2014_file4.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.ofs" "murBlockMini1_2014_Mur5_optimized2014_file4.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_file4.oa" "murBlockMini1_2014_Mur5_optimized2014_bump2d4.bv"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_lambert9SG1.msg" "murBlockMini1_2014_pasted__Mur5_optimized2014_materialInfo4.sg"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.c" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.c"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.tf" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.tf"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.rf" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.rf"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.mu" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.mu"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.mv" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.mv"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.s" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.s"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.wu" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.wu"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.wv" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.wv"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.re" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.re"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.of" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.of"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.r" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.ro"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.n" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.n"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.vt1" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.vt1"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.vt2" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.vt2"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.vt3" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.vt3"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.vc1" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.vc1"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.o" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.uv"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.ofs" "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.fs"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.oa" "murBlockMini1_2014_pasted__Mur5_optimized2014_bump2d4.bv"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.c" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.c"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.tf" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.tf"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.rf" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.rf"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.mu" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.mu"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.mv" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.mv"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.s" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.s"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.wu" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.wu"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.wv" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.wv"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.re" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.re"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.of" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.of"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.r" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.ro"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.n" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.n"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.vt1" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.vt1"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.vt2" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.vt2"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.vt3" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.vt3"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.vc1" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.vc1"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.o" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.uv"
		;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.ofs" "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.fs"
		;
connectAttr "murBlockMini1_2014_polySurface34SG.msg" "murBlockMini1_2014_materialInfo3.sg"
		;
connectAttr "murBlockMini1_2014_place2dTexture6.o" "murBlockMini1_2014_lambert1_Flattened_Diffuse.uv"
		;
connectAttr "murBlockMini1_2014_place2dTexture6.ofu" "murBlockMini1_2014_lambert1_Flattened_Diffuse.ofu"
		;
connectAttr "murBlockMini1_2014_place2dTexture6.ofv" "murBlockMini1_2014_lambert1_Flattened_Diffuse.ofv"
		;
connectAttr "murBlockMini1_2014_place2dTexture6.rf" "murBlockMini1_2014_lambert1_Flattened_Diffuse.rf"
		;
connectAttr "murBlockMini1_2014_place2dTexture6.reu" "murBlockMini1_2014_lambert1_Flattened_Diffuse.reu"
		;
connectAttr "murBlockMini1_2014_place2dTexture6.rev" "murBlockMini1_2014_lambert1_Flattened_Diffuse.rev"
		;
connectAttr "murBlockMini1_2014_place2dTexture6.vt1" "murBlockMini1_2014_lambert1_Flattened_Diffuse.vt1"
		;
connectAttr "murBlockMini1_2014_place2dTexture6.vt2" "murBlockMini1_2014_lambert1_Flattened_Diffuse.vt2"
		;
connectAttr "murBlockMini1_2014_place2dTexture6.vt3" "murBlockMini1_2014_lambert1_Flattened_Diffuse.vt3"
		;
connectAttr "murBlockMini1_2014_place2dTexture6.vc1" "murBlockMini1_2014_lambert1_Flattened_Diffuse.vc1"
		;
connectAttr "murBlockMini1_2014_place2dTexture6.ofs" "murBlockMini1_2014_lambert1_Flattened_Diffuse.fs"
		;
connectAttr "murBlockMini1_2014_polySurface34SG1.msg" "murBlockMini1_2014_materialInfo4.sg"
		;
connectAttr "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.oa" "murBlockMini1_2014_bump2d3.bv"
		;
connectAttr "murBlockMini1_2014_place2dTexture7.o" "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.uv"
		;
connectAttr "murBlockMini1_2014_place2dTexture7.ofu" "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.ofu"
		;
connectAttr "murBlockMini1_2014_place2dTexture7.ofv" "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.ofv"
		;
connectAttr "murBlockMini1_2014_place2dTexture7.rf" "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.rf"
		;
connectAttr "murBlockMini1_2014_place2dTexture7.reu" "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.reu"
		;
connectAttr "murBlockMini1_2014_place2dTexture7.rev" "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.rev"
		;
connectAttr "murBlockMini1_2014_place2dTexture7.vt1" "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.vt1"
		;
connectAttr "murBlockMini1_2014_place2dTexture7.vt2" "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.vt2"
		;
connectAttr "murBlockMini1_2014_place2dTexture7.vt3" "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.vt3"
		;
connectAttr "murBlockMini1_2014_place2dTexture7.vc1" "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.vc1"
		;
connectAttr "murBlockMini1_2014_place2dTexture7.ofs" "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.fs"
		;
connectAttr "murBlockMini1_2014_lambert1_Flattened_Diffuse.oc" "murBlockMini1_2014_lambert12.c"
		;
connectAttr "murBlockMini1_2014_bump2d4.o" "murBlockMini1_2014_lambert12.n";
connectAttr "murBlockMini1_2014_ReflectionMap.oc" "murBlockMini1_2014_lambert12.rc"
		;
connectAttr "murBlockMini1_2014_lambert12.oc" "murBlockMini1_2014_polySurface34SG2.ss"
		;
connectAttr "murBlockMini1_2014_polySurface34SG2.msg" "murBlockMini1_2014_materialInfo5.sg"
		;
connectAttr "murBlockMini1_2014_lambert12.msg" "murBlockMini1_2014_materialInfo5.m"
		;
connectAttr "murBlockMini1_2014_lambert1_Flattened_Diffuse.msg" "murBlockMini1_2014_materialInfo5.t"
		 -na;
connectAttr "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.oa" "murBlockMini1_2014_bump2d4.bv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.oc" "murBlockMini1_2014_lambert8.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_bump2d1.o" "murBlockMini1_2014_lambert8.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap.oc" "murBlockMini1_2014_lambert8.rc"
		;
connectAttr "murBlockMini1_2014_lambert8.oc" "murBlockMini1_2014_Mur5_optimized2014_5_polySurface33SG.ss"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_polySurface33SG.msg" "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo1.sg"
		;
connectAttr "murBlockMini1_2014_lambert8.msg" "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo1.m"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.msg" "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo1.t"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture1.o" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture1.ofu" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture1.ofv" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture1.rf" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture1.reu" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture1.rev" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture1.vt1" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture1.vt2" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture1.vt3" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture1.vc1" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture1.ofs" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murBlockMini1_2014_Mur5_optimized2014_5_bump2d1.bv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture2.o" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture2.ofu" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture2.ofv" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture2.rf" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture2.reu" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture2.rev" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture2.vt1" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture2.vt2" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture2.vt3" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture2.vc1" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture2.ofs" "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture3.o" "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture3.ofu" "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture3.ofv" "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture3.rf" "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture3.reu" "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture3.rev" "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture3.vt1" "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture3.vt2" "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture3.vt3" "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture3.vc1" "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture3.ofs" "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_file1.oc" "murBlockMini1_2014_lambert9.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_file1.ot" "murBlockMini1_2014_lambert9.it"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_bump2d2.o" "murBlockMini1_2014_lambert9.n"
		;
connectAttr "murBlockMini1_2014_lambert9.oc" "murBlockMini1_2014_Mur5_optimized2014_5_lambert9SG.ss"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_lambert9SG.msg" "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo2.sg"
		;
connectAttr "murBlockMini1_2014_lambert9.msg" "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo2.m"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_file1.msg" "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo2.t"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.c" "murBlockMini1_2014_Mur5_optimized2014_5_file1.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.tf" "murBlockMini1_2014_Mur5_optimized2014_5_file1.tf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.rf" "murBlockMini1_2014_Mur5_optimized2014_5_file1.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.mu" "murBlockMini1_2014_Mur5_optimized2014_5_file1.mu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.mv" "murBlockMini1_2014_Mur5_optimized2014_5_file1.mv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.s" "murBlockMini1_2014_Mur5_optimized2014_5_file1.s"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.wu" "murBlockMini1_2014_Mur5_optimized2014_5_file1.wu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.wv" "murBlockMini1_2014_Mur5_optimized2014_5_file1.wv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.re" "murBlockMini1_2014_Mur5_optimized2014_5_file1.re"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.of" "murBlockMini1_2014_Mur5_optimized2014_5_file1.of"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.r" "murBlockMini1_2014_Mur5_optimized2014_5_file1.ro"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.n" "murBlockMini1_2014_Mur5_optimized2014_5_file1.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.vt1" "murBlockMini1_2014_Mur5_optimized2014_5_file1.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.vt2" "murBlockMini1_2014_Mur5_optimized2014_5_file1.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.vt3" "murBlockMini1_2014_Mur5_optimized2014_5_file1.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.vc1" "murBlockMini1_2014_Mur5_optimized2014_5_file1.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.o" "murBlockMini1_2014_Mur5_optimized2014_5_file1.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.ofs" "murBlockMini1_2014_Mur5_optimized2014_5_file1.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.c" "murBlockMini1_2014_Mur5_optimized2014_5_file2.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.tf" "murBlockMini1_2014_Mur5_optimized2014_5_file2.tf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.rf" "murBlockMini1_2014_Mur5_optimized2014_5_file2.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.mu" "murBlockMini1_2014_Mur5_optimized2014_5_file2.mu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.mv" "murBlockMini1_2014_Mur5_optimized2014_5_file2.mv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.s" "murBlockMini1_2014_Mur5_optimized2014_5_file2.s"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.wu" "murBlockMini1_2014_Mur5_optimized2014_5_file2.wu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.wv" "murBlockMini1_2014_Mur5_optimized2014_5_file2.wv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.re" "murBlockMini1_2014_Mur5_optimized2014_5_file2.re"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.of" "murBlockMini1_2014_Mur5_optimized2014_5_file2.of"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.r" "murBlockMini1_2014_Mur5_optimized2014_5_file2.ro"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.n" "murBlockMini1_2014_Mur5_optimized2014_5_file2.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.vt1" "murBlockMini1_2014_Mur5_optimized2014_5_file2.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.vt2" "murBlockMini1_2014_Mur5_optimized2014_5_file2.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.vt3" "murBlockMini1_2014_Mur5_optimized2014_5_file2.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.vc1" "murBlockMini1_2014_Mur5_optimized2014_5_file2.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.o" "murBlockMini1_2014_Mur5_optimized2014_5_file2.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.ofs" "murBlockMini1_2014_Mur5_optimized2014_5_file2.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_file2.oa" "murBlockMini1_2014_Mur5_optimized2014_5_bump2d2.bv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.oc" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_bump2d1.o" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap.oc" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8.rc"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_lambert8.oc" "murBlockMini1_2014_Mur5_optimized2014_2_polySurface33SG.ss"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_polySurface33SG.msg" "murBlockMini1_2014_Mur5_optimized2014_2_materialInfo1.sg"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_lambert8.msg" "murBlockMini1_2014_Mur5_optimized2014_2_materialInfo1.m"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" "murBlockMini1_2014_Mur5_optimized2014_2_materialInfo1.t"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture1.o" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture1.ofu" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture1.ofv" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture1.rf" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture1.reu" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture1.rev" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture1.vt1" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture1.vt2" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture1.vt3" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture1.vc1" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture1.ofs" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murBlockMini1_2014_Mur5_optimized2014_2_bump2d1.bv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture2.o" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture2.ofu" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture2.ofv" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture2.rf" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture2.reu" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture2.rev" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture2.vt1" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture2.vt2" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture2.vt3" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture2.vc1" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture2.ofs" "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture3.o" "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture3.ofu" "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture3.ofv" "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture3.rf" "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture3.reu" "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture3.rev" "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture3.vt1" "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture3.vt2" "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture3.vt3" "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture3.vc1" "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture3.ofs" "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_file1.oc" "murBlockMini1_2014_Mur5_optimized2014_2_lambert9.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_file1.ot" "murBlockMini1_2014_Mur5_optimized2014_2_lambert9.it"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_bump2d2.o" "murBlockMini1_2014_Mur5_optimized2014_2_lambert9.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_lambert9.oc" "murBlockMini1_2014_Mur5_optimized2014_2_lambert9SG.ss"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_lambert9SG.msg" "murBlockMini1_2014_Mur5_optimized2014_2_materialInfo2.sg"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_lambert9.msg" "murBlockMini1_2014_Mur5_optimized2014_2_materialInfo2.m"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_file1.msg" "murBlockMini1_2014_Mur5_optimized2014_2_materialInfo2.t"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.c" "murBlockMini1_2014_Mur5_optimized2014_2_file1.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.tf" "murBlockMini1_2014_Mur5_optimized2014_2_file1.tf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.rf" "murBlockMini1_2014_Mur5_optimized2014_2_file1.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.mu" "murBlockMini1_2014_Mur5_optimized2014_2_file1.mu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.mv" "murBlockMini1_2014_Mur5_optimized2014_2_file1.mv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.s" "murBlockMini1_2014_Mur5_optimized2014_2_file1.s"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.wu" "murBlockMini1_2014_Mur5_optimized2014_2_file1.wu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.wv" "murBlockMini1_2014_Mur5_optimized2014_2_file1.wv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.re" "murBlockMini1_2014_Mur5_optimized2014_2_file1.re"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.of" "murBlockMini1_2014_Mur5_optimized2014_2_file1.of"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.r" "murBlockMini1_2014_Mur5_optimized2014_2_file1.ro"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.n" "murBlockMini1_2014_Mur5_optimized2014_2_file1.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.vt1" "murBlockMini1_2014_Mur5_optimized2014_2_file1.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.vt2" "murBlockMini1_2014_Mur5_optimized2014_2_file1.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.vt3" "murBlockMini1_2014_Mur5_optimized2014_2_file1.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.vc1" "murBlockMini1_2014_Mur5_optimized2014_2_file1.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.o" "murBlockMini1_2014_Mur5_optimized2014_2_file1.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.ofs" "murBlockMini1_2014_Mur5_optimized2014_2_file1.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.c" "murBlockMini1_2014_Mur5_optimized2014_2_file2.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.tf" "murBlockMini1_2014_Mur5_optimized2014_2_file2.tf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.rf" "murBlockMini1_2014_Mur5_optimized2014_2_file2.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.mu" "murBlockMini1_2014_Mur5_optimized2014_2_file2.mu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.mv" "murBlockMini1_2014_Mur5_optimized2014_2_file2.mv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.s" "murBlockMini1_2014_Mur5_optimized2014_2_file2.s"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.wu" "murBlockMini1_2014_Mur5_optimized2014_2_file2.wu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.wv" "murBlockMini1_2014_Mur5_optimized2014_2_file2.wv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.re" "murBlockMini1_2014_Mur5_optimized2014_2_file2.re"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.of" "murBlockMini1_2014_Mur5_optimized2014_2_file2.of"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.r" "murBlockMini1_2014_Mur5_optimized2014_2_file2.ro"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.n" "murBlockMini1_2014_Mur5_optimized2014_2_file2.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.vt1" "murBlockMini1_2014_Mur5_optimized2014_2_file2.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.vt2" "murBlockMini1_2014_Mur5_optimized2014_2_file2.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.vt3" "murBlockMini1_2014_Mur5_optimized2014_2_file2.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.vc1" "murBlockMini1_2014_Mur5_optimized2014_2_file2.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.o" "murBlockMini1_2014_Mur5_optimized2014_2_file2.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.ofs" "murBlockMini1_2014_Mur5_optimized2014_2_file2.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_file2.oa" "murBlockMini1_2014_Mur5_optimized2014_2_bump2d2.bv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.oc" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_bump2d1.o" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.oc" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8.rc"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_lambert8.oc" "murBlockMini1_2014_Mur5_optimized2014_4_polySurface33SG.ss"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_polySurface33SG.msg" "murBlockMini1_2014_Mur5_optimized2014_4_materialInfo1.sg"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_lambert8.msg" "murBlockMini1_2014_Mur5_optimized2014_4_materialInfo1.m"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" "murBlockMini1_2014_Mur5_optimized2014_4_materialInfo1.t"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture1.o" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture1.ofu" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture1.ofv" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture1.rf" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture1.reu" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture1.rev" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture1.vt1" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture1.vt2" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture1.vt3" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture1.vc1" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture1.ofs" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "murBlockMini1_2014_Mur5_optimized2014_4_bump2d1.bv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture2.o" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture2.ofu" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture2.ofv" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture2.rf" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture2.reu" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture2.rev" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture2.vt1" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture2.vt2" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture2.vt3" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture2.vc1" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture2.ofs" "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture3.o" "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture3.ofu" "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture3.ofv" "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture3.rf" "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture3.reu" "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture3.rev" "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture3.vt1" "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture3.vt2" "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture3.vt3" "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture3.vc1" "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture3.ofs" "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_file1.oc" "murBlockMini1_2014_Mur5_optimized2014_4_lambert9.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_file1.ot" "murBlockMini1_2014_Mur5_optimized2014_4_lambert9.it"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_bump2d2.o" "murBlockMini1_2014_Mur5_optimized2014_4_lambert9.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_lambert9.oc" "murBlockMini1_2014_Mur5_optimized2014_4_lambert9SG.ss"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_lambert9SG.msg" "murBlockMini1_2014_Mur5_optimized2014_4_materialInfo2.sg"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_lambert9.msg" "murBlockMini1_2014_Mur5_optimized2014_4_materialInfo2.m"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_file1.msg" "murBlockMini1_2014_Mur5_optimized2014_4_materialInfo2.t"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.c" "murBlockMini1_2014_Mur5_optimized2014_4_file1.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.tf" "murBlockMini1_2014_Mur5_optimized2014_4_file1.tf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.rf" "murBlockMini1_2014_Mur5_optimized2014_4_file1.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.mu" "murBlockMini1_2014_Mur5_optimized2014_4_file1.mu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.mv" "murBlockMini1_2014_Mur5_optimized2014_4_file1.mv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.s" "murBlockMini1_2014_Mur5_optimized2014_4_file1.s"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.wu" "murBlockMini1_2014_Mur5_optimized2014_4_file1.wu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.wv" "murBlockMini1_2014_Mur5_optimized2014_4_file1.wv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.re" "murBlockMini1_2014_Mur5_optimized2014_4_file1.re"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.of" "murBlockMini1_2014_Mur5_optimized2014_4_file1.of"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.r" "murBlockMini1_2014_Mur5_optimized2014_4_file1.ro"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.n" "murBlockMini1_2014_Mur5_optimized2014_4_file1.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.vt1" "murBlockMini1_2014_Mur5_optimized2014_4_file1.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.vt2" "murBlockMini1_2014_Mur5_optimized2014_4_file1.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.vt3" "murBlockMini1_2014_Mur5_optimized2014_4_file1.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.vc1" "murBlockMini1_2014_Mur5_optimized2014_4_file1.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.o" "murBlockMini1_2014_Mur5_optimized2014_4_file1.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.ofs" "murBlockMini1_2014_Mur5_optimized2014_4_file1.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.c" "murBlockMini1_2014_Mur5_optimized2014_4_file2.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.tf" "murBlockMini1_2014_Mur5_optimized2014_4_file2.tf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.rf" "murBlockMini1_2014_Mur5_optimized2014_4_file2.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.mu" "murBlockMini1_2014_Mur5_optimized2014_4_file2.mu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.mv" "murBlockMini1_2014_Mur5_optimized2014_4_file2.mv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.s" "murBlockMini1_2014_Mur5_optimized2014_4_file2.s"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.wu" "murBlockMini1_2014_Mur5_optimized2014_4_file2.wu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.wv" "murBlockMini1_2014_Mur5_optimized2014_4_file2.wv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.re" "murBlockMini1_2014_Mur5_optimized2014_4_file2.re"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.of" "murBlockMini1_2014_Mur5_optimized2014_4_file2.of"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.r" "murBlockMini1_2014_Mur5_optimized2014_4_file2.ro"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.n" "murBlockMini1_2014_Mur5_optimized2014_4_file2.n"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.vt1" "murBlockMini1_2014_Mur5_optimized2014_4_file2.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.vt2" "murBlockMini1_2014_Mur5_optimized2014_4_file2.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.vt3" "murBlockMini1_2014_Mur5_optimized2014_4_file2.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.vc1" "murBlockMini1_2014_Mur5_optimized2014_4_file2.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.o" "murBlockMini1_2014_Mur5_optimized2014_4_file2.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.ofs" "murBlockMini1_2014_Mur5_optimized2014_4_file2.fs"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_file2.oa" "murBlockMini1_2014_Mur5_optimized2014_4_bump2d2.bv"
		;
connectAttr "murBlockMini1_2014_lambert9_Flattened_Diffuse.oc" "murBlockMini1_2014_lambert10.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_bump2d3.o" "murBlockMini1_2014_lambert10.n"
		;
connectAttr "murBlockMini1_2014_lambert9_Flattened_Opacity.ot" "murBlockMini1_2014_lambert10.it"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.oc" "murBlockMini1_2014_lambert10.rc"
		;
connectAttr "murBlockMini1_2014_lambert10.oc" "murBlockMini1_2014_wallSG.ss";
connectAttr "murBlockMini1_2014_wallSG.msg" "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo3.sg"
		;
connectAttr "murBlockMini1_2014_lambert10.msg" "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo3.m"
		;
connectAttr "murBlockMini1_2014_lambert9_Flattened_Diffuse.msg" "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo3.t"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture6.o" "murBlockMini1_2014_lambert9_Flattened_Diffuse.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture6.ofu" "murBlockMini1_2014_lambert9_Flattened_Diffuse.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture6.ofv" "murBlockMini1_2014_lambert9_Flattened_Diffuse.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture6.rf" "murBlockMini1_2014_lambert9_Flattened_Diffuse.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture6.reu" "murBlockMini1_2014_lambert9_Flattened_Diffuse.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture6.rev" "murBlockMini1_2014_lambert9_Flattened_Diffuse.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture6.vt1" "murBlockMini1_2014_lambert9_Flattened_Diffuse.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture6.vt2" "murBlockMini1_2014_lambert9_Flattened_Diffuse.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture6.vt3" "murBlockMini1_2014_lambert9_Flattened_Diffuse.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture6.vc1" "murBlockMini1_2014_lambert9_Flattened_Diffuse.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture6.ofs" "murBlockMini1_2014_lambert9_Flattened_Diffuse.fs"
		;
connectAttr "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map.oa" "murBlockMini1_2014_Mur5_optimized2014_5_bump2d3.bv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture7.o" "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture7.ofu" "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture7.ofv" "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture7.rf" "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture7.reu" "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture7.rev" "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture7.vt1" "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture7.vt2" "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture7.vt3" "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture7.vc1" "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture7.ofs" "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murBlockMini1_2014_place2dTexture8.o" "murBlockMini1_2014_lambert9_Flattened_Opacity.uv"
		;
connectAttr "murBlockMini1_2014_place2dTexture8.ofu" "murBlockMini1_2014_lambert9_Flattened_Opacity.ofu"
		;
connectAttr "murBlockMini1_2014_place2dTexture8.ofv" "murBlockMini1_2014_lambert9_Flattened_Opacity.ofv"
		;
connectAttr "murBlockMini1_2014_place2dTexture8.rf" "murBlockMini1_2014_lambert9_Flattened_Opacity.rf"
		;
connectAttr "murBlockMini1_2014_place2dTexture8.reu" "murBlockMini1_2014_lambert9_Flattened_Opacity.reu"
		;
connectAttr "murBlockMini1_2014_place2dTexture8.rev" "murBlockMini1_2014_lambert9_Flattened_Opacity.rev"
		;
connectAttr "murBlockMini1_2014_place2dTexture8.vt1" "murBlockMini1_2014_lambert9_Flattened_Opacity.vt1"
		;
connectAttr "murBlockMini1_2014_place2dTexture8.vt2" "murBlockMini1_2014_lambert9_Flattened_Opacity.vt2"
		;
connectAttr "murBlockMini1_2014_place2dTexture8.vt3" "murBlockMini1_2014_lambert9_Flattened_Opacity.vt3"
		;
connectAttr "murBlockMini1_2014_place2dTexture8.vc1" "murBlockMini1_2014_lambert9_Flattened_Opacity.vc1"
		;
connectAttr "murBlockMini1_2014_place2dTexture8.ofs" "murBlockMini1_2014_lambert9_Flattened_Opacity.fs"
		;
connectAttr "murBlockMini1_2014_lambert11_Flattened_Diffuse.oc" "murBlockMini1_2014_lambert11.c"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_bump2d4.o" "murBlockMini1_2014_lambert11.n"
		;
connectAttr "murBlockMini1_2014_lambert11_Flattened_Opacity.ot" "murBlockMini1_2014_lambert11.it"
		;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.oc" "murBlockMini1_2014_lambert11.rc"
		;
connectAttr "murBlockMini1_2014_lambert11.oc" "murBlockMini1_2014_wallSG1.ss";
connectAttr "murBlockMini1_2014_wallSG1.msg" "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo4.sg"
		;
connectAttr "murBlockMini1_2014_lambert11.msg" "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo4.m"
		;
connectAttr "murBlockMini1_2014_lambert11_Flattened_Diffuse.msg" "murBlockMini1_2014_Mur5_optimized2014_5_materialInfo4.t"
		 -na;
connectAttr "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map.oa" "murBlockMini1_2014_Mur5_optimized2014_5_bump2d4.bv"
		;
connectAttr "murBlockMini1_2014_place2dTexture9.o" "murBlockMini1_2014_lambert11_Flattened_Diffuse.uv"
		;
connectAttr "murBlockMini1_2014_place2dTexture9.ofu" "murBlockMini1_2014_lambert11_Flattened_Diffuse.ofu"
		;
connectAttr "murBlockMini1_2014_place2dTexture9.ofv" "murBlockMini1_2014_lambert11_Flattened_Diffuse.ofv"
		;
connectAttr "murBlockMini1_2014_place2dTexture9.rf" "murBlockMini1_2014_lambert11_Flattened_Diffuse.rf"
		;
connectAttr "murBlockMini1_2014_place2dTexture9.reu" "murBlockMini1_2014_lambert11_Flattened_Diffuse.reu"
		;
connectAttr "murBlockMini1_2014_place2dTexture9.rev" "murBlockMini1_2014_lambert11_Flattened_Diffuse.rev"
		;
connectAttr "murBlockMini1_2014_place2dTexture9.vt1" "murBlockMini1_2014_lambert11_Flattened_Diffuse.vt1"
		;
connectAttr "murBlockMini1_2014_place2dTexture9.vt2" "murBlockMini1_2014_lambert11_Flattened_Diffuse.vt2"
		;
connectAttr "murBlockMini1_2014_place2dTexture9.vt3" "murBlockMini1_2014_lambert11_Flattened_Diffuse.vt3"
		;
connectAttr "murBlockMini1_2014_place2dTexture9.vc1" "murBlockMini1_2014_lambert11_Flattened_Diffuse.vc1"
		;
connectAttr "murBlockMini1_2014_place2dTexture9.ofs" "murBlockMini1_2014_lambert11_Flattened_Diffuse.fs"
		;
connectAttr "murBlockMini1_2014_place2dTexture10.o" "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "murBlockMini1_2014_place2dTexture10.ofu" "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "murBlockMini1_2014_place2dTexture10.ofv" "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "murBlockMini1_2014_place2dTexture10.rf" "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "murBlockMini1_2014_place2dTexture10.reu" "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "murBlockMini1_2014_place2dTexture10.rev" "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "murBlockMini1_2014_place2dTexture10.vt1" "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "murBlockMini1_2014_place2dTexture10.vt2" "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "murBlockMini1_2014_place2dTexture10.vt3" "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "murBlockMini1_2014_place2dTexture10.vc1" "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "murBlockMini1_2014_place2dTexture10.ofs" "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "murBlockMini1_2014_place2dTexture11.o" "murBlockMini1_2014_lambert11_Flattened_Opacity.uv"
		;
connectAttr "murBlockMini1_2014_place2dTexture11.ofu" "murBlockMini1_2014_lambert11_Flattened_Opacity.ofu"
		;
connectAttr "murBlockMini1_2014_place2dTexture11.ofv" "murBlockMini1_2014_lambert11_Flattened_Opacity.ofv"
		;
connectAttr "murBlockMini1_2014_place2dTexture11.rf" "murBlockMini1_2014_lambert11_Flattened_Opacity.rf"
		;
connectAttr "murBlockMini1_2014_place2dTexture11.reu" "murBlockMini1_2014_lambert11_Flattened_Opacity.reu"
		;
connectAttr "murBlockMini1_2014_place2dTexture11.rev" "murBlockMini1_2014_lambert11_Flattened_Opacity.rev"
		;
connectAttr "murBlockMini1_2014_place2dTexture11.vt1" "murBlockMini1_2014_lambert11_Flattened_Opacity.vt1"
		;
connectAttr "murBlockMini1_2014_place2dTexture11.vt2" "murBlockMini1_2014_lambert11_Flattened_Opacity.vt2"
		;
connectAttr "murBlockMini1_2014_place2dTexture11.vt3" "murBlockMini1_2014_lambert11_Flattened_Opacity.vt3"
		;
connectAttr "murBlockMini1_2014_place2dTexture11.vc1" "murBlockMini1_2014_lambert11_Flattened_Opacity.vc1"
		;
connectAttr "murBlockMini1_2014_place2dTexture11.ofs" "murBlockMini1_2014_lambert11_Flattened_Opacity.fs"
		;
connectAttr "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.oc" "Mur5_optimized2014_5_lambert8.c"
		;
connectAttr "Mur5_optimized2014_5_bump2d5.o" "Mur5_optimized2014_5_lambert8.n";
connectAttr "Mur5_optimized2014_5_ReflectionMap1.oc" "Mur5_optimized2014_5_lambert8.rc"
		;
connectAttr "Mur5_optimized2014_5_lambert8.oc" "Mur5_optimized2014_5_polySurface33SG1.ss"
		;
connectAttr "Mur5_optimized2014_5_polySurface33SG1.msg" "Mur5_optimized2014_5_materialInfo5.sg"
		;
connectAttr "Mur5_optimized2014_5_lambert8.msg" "Mur5_optimized2014_5_materialInfo5.m"
		;
connectAttr "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.msg" "Mur5_optimized2014_5_materialInfo5.t"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture8.o" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture8.ofu" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture8.ofv" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture8.rf" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture8.reu" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture8.rev" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture8.vt1" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture8.vt2" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture8.vt3" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture8.vc1" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture8.ofs" "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.fs"
		;
connectAttr "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2.oa" "Mur5_optimized2014_5_bump2d5.bv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture9.o" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture9.ofu" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture9.ofv" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture9.rf" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture9.reu" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture9.rev" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture9.vt1" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture9.vt2" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture9.vt3" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture9.vc1" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture9.ofs" "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2.fs"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture10.o" "Mur5_optimized2014_5_ReflectionMap1.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture10.ofu" "Mur5_optimized2014_5_ReflectionMap1.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture10.ofv" "Mur5_optimized2014_5_ReflectionMap1.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture10.rf" "Mur5_optimized2014_5_ReflectionMap1.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture10.reu" "Mur5_optimized2014_5_ReflectionMap1.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture10.rev" "Mur5_optimized2014_5_ReflectionMap1.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture10.vt1" "Mur5_optimized2014_5_ReflectionMap1.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture10.vt2" "Mur5_optimized2014_5_ReflectionMap1.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture10.vt3" "Mur5_optimized2014_5_ReflectionMap1.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture10.vc1" "Mur5_optimized2014_5_ReflectionMap1.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture10.ofs" "Mur5_optimized2014_5_ReflectionMap1.fs"
		;
connectAttr "Mur5_optimized2014_5_file3.oc" "Mur5_optimized2014_5_lambert9.c";
connectAttr "Mur5_optimized2014_5_file3.ot" "Mur5_optimized2014_5_lambert9.it";
connectAttr "Mur5_optimized2014_5_bump2d6.o" "Mur5_optimized2014_5_lambert9.n";
connectAttr "Mur5_optimized2014_5_lambert9.oc" "Mur5_optimized2014_5_lambert9SG1.ss"
		;
connectAttr "Mur5_optimized2014_5_lambert9SG1.msg" "Mur5_optimized2014_5_materialInfo6.sg"
		;
connectAttr "Mur5_optimized2014_5_lambert9.msg" "Mur5_optimized2014_5_materialInfo6.m"
		;
connectAttr "Mur5_optimized2014_5_file3.msg" "Mur5_optimized2014_5_materialInfo6.t"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture11.c" "Mur5_optimized2014_5_file3.c"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.tf" "Mur5_optimized2014_5_file3.tf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.rf" "Mur5_optimized2014_5_file3.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.mu" "Mur5_optimized2014_5_file3.mu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.mv" "Mur5_optimized2014_5_file3.mv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.s" "Mur5_optimized2014_5_file3.s"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.wu" "Mur5_optimized2014_5_file3.wu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.wv" "Mur5_optimized2014_5_file3.wv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.re" "Mur5_optimized2014_5_file3.re"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.of" "Mur5_optimized2014_5_file3.of"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.r" "Mur5_optimized2014_5_file3.ro"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.n" "Mur5_optimized2014_5_file3.n"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.vt1" "Mur5_optimized2014_5_file3.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.vt2" "Mur5_optimized2014_5_file3.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.vt3" "Mur5_optimized2014_5_file3.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.vc1" "Mur5_optimized2014_5_file3.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.o" "Mur5_optimized2014_5_file3.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture11.ofs" "Mur5_optimized2014_5_file3.fs"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.c" "Mur5_optimized2014_5_file4.c"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.tf" "Mur5_optimized2014_5_file4.tf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.rf" "Mur5_optimized2014_5_file4.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.mu" "Mur5_optimized2014_5_file4.mu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.mv" "Mur5_optimized2014_5_file4.mv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.s" "Mur5_optimized2014_5_file4.s"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.wu" "Mur5_optimized2014_5_file4.wu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.wv" "Mur5_optimized2014_5_file4.wv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.re" "Mur5_optimized2014_5_file4.re"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.of" "Mur5_optimized2014_5_file4.of"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.r" "Mur5_optimized2014_5_file4.ro"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.n" "Mur5_optimized2014_5_file4.n"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.vt1" "Mur5_optimized2014_5_file4.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.vt2" "Mur5_optimized2014_5_file4.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.vt3" "Mur5_optimized2014_5_file4.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.vc1" "Mur5_optimized2014_5_file4.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.o" "Mur5_optimized2014_5_file4.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture12.ofs" "Mur5_optimized2014_5_file4.fs"
		;
connectAttr "Mur5_optimized2014_5_file4.oa" "Mur5_optimized2014_5_bump2d6.bv";
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.oc" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8.c"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_bump2d1.o" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8.n"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap.oc" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8.rc"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8.oc" "Mur5_optimized2014_5_Mur5_optimized2014_2_polySurface33SG.ss"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_polySurface33SG.msg" "Mur5_optimized2014_5_Mur5_optimized2014_2_materialInfo1.sg"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8.msg" "Mur5_optimized2014_5_Mur5_optimized2014_2_materialInfo1.m"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" "Mur5_optimized2014_5_Mur5_optimized2014_2_materialInfo1.t"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture1.o" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture1.ofu" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture1.ofv" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture1.rf" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture1.reu" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture1.rev" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture1.vt1" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture1.vt2" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture1.vt3" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture1.vc1" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture1.ofs" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "Mur5_optimized2014_5_Mur5_optimized2014_2_bump2d1.bv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture2.o" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture2.ofu" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture2.ofv" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture2.rf" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture2.reu" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture2.rev" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture2.vt1" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture2.vt2" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture2.vt3" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture2.vc1" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture2.ofs" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture3.o" "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap.uv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture3.ofu" "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap.ofu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture3.ofv" "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap.ofv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture3.rf" "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap.rf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture3.reu" "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap.reu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture3.rev" "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap.rev"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture3.vt1" "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap.vt1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture3.vt2" "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap.vt2"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture3.vt3" "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap.vt3"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture3.vc1" "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap.vc1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture3.ofs" "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap.fs"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.oc" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert9.c"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.ot" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert9.it"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_bump2d2.o" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert9.n"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert9.oc" "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert9SG.ss"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert9SG.msg" "Mur5_optimized2014_5_Mur5_optimized2014_2_materialInfo2.sg"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert9.msg" "Mur5_optimized2014_5_Mur5_optimized2014_2_materialInfo2.m"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.msg" "Mur5_optimized2014_5_Mur5_optimized2014_2_materialInfo2.t"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.c" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.c"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.tf" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.tf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.rf" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.rf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.mu" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.mu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.mv" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.mv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.s" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.s"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.wu" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.wu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.wv" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.wv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.re" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.re"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.of" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.of"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.r" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.ro"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.n" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.n"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.vt1" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.vt1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.vt2" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.vt2"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.vt3" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.vt3"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.vc1" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.vc1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.o" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.uv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.ofs" "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.fs"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.c" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.c"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.tf" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.tf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.rf" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.rf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.mu" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.mu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.mv" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.mv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.s" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.s"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.wu" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.wu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.wv" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.wv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.re" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.re"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.of" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.of"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.r" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.ro"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.n" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.n"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.vt1" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.vt1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.vt2" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.vt2"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.vt3" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.vt3"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.vc1" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.vc1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.o" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.uv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.ofs" "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.fs"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.oa" "Mur5_optimized2014_5_Mur5_optimized2014_2_bump2d2.bv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.oc" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8.c"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_bump2d1.o" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8.n"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.oc" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8.rc"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8.oc" "Mur5_optimized2014_5_Mur5_optimized2014_4_polySurface33SG.ss"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_polySurface33SG.msg" "Mur5_optimized2014_5_Mur5_optimized2014_4_materialInfo1.sg"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8.msg" "Mur5_optimized2014_5_Mur5_optimized2014_4_materialInfo1.m"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" "Mur5_optimized2014_5_Mur5_optimized2014_4_materialInfo1.t"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture1.o" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture1.ofu" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture1.ofv" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture1.rf" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture1.reu" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture1.rev" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture1.vt1" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture1.vt2" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture1.vt3" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture1.vc1" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture1.ofs" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "Mur5_optimized2014_5_Mur5_optimized2014_4_bump2d1.bv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture2.o" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture2.ofu" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture2.ofv" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture2.rf" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture2.reu" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture2.rev" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture2.vt1" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture2.vt2" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture2.vt3" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture2.vc1" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture2.ofs" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture3.o" "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.uv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture3.ofu" "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.ofu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture3.ofv" "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.ofv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture3.rf" "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.rf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture3.reu" "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.reu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture3.rev" "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.rev"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture3.vt1" "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.vt1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture3.vt2" "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.vt2"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture3.vt3" "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.vt3"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture3.vc1" "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.vc1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture3.ofs" "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.fs"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.oc" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert9.c"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.ot" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert9.it"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_bump2d2.o" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert9.n"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert9.oc" "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert9SG.ss"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert9SG.msg" "Mur5_optimized2014_5_Mur5_optimized2014_4_materialInfo2.sg"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert9.msg" "Mur5_optimized2014_5_Mur5_optimized2014_4_materialInfo2.m"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.msg" "Mur5_optimized2014_5_Mur5_optimized2014_4_materialInfo2.t"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.c" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.c"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.tf" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.tf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.rf" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.rf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.mu" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.mu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.mv" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.mv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.s" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.s"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.wu" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.wu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.wv" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.wv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.re" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.re"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.of" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.of"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.r" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.ro"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.n" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.n"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.vt1" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.vt1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.vt2" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.vt2"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.vt3" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.vt3"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.vc1" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.vc1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.o" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.uv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.ofs" "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.fs"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.c" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.c"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.tf" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.tf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.rf" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.rf"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.mu" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.mu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.mv" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.mv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.s" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.s"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.wu" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.wu"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.wv" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.wv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.re" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.re"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.of" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.of"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.r" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.ro"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.n" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.n"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.vt1" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.vt1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.vt2" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.vt2"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.vt3" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.vt3"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.vc1" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.vc1"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.o" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.uv"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.ofs" "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.fs"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.oa" "Mur5_optimized2014_5_Mur5_optimized2014_4_bump2d2.bv"
		;
connectAttr "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.oc" "Mur5_optimized2014_5_lambert10.c"
		;
connectAttr "Mur5_optimized2014_5_bump2d7.o" "Mur5_optimized2014_5_lambert10.n";
connectAttr "Mur5_optimized2014_5_lambert9_Flattened_Opacity.ot" "Mur5_optimized2014_5_lambert10.it"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.oc" "Mur5_optimized2014_5_lambert10.rc"
		;
connectAttr "Mur5_optimized2014_5_lambert10.oc" "Mur5_optimized2014_5_wallSG.ss"
		;
connectAttr "Mur5_optimized2014_5_wallSG.msg" "Mur5_optimized2014_5_materialInfo7.sg"
		;
connectAttr "Mur5_optimized2014_5_lambert10.msg" "Mur5_optimized2014_5_materialInfo7.m"
		;
connectAttr "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.msg" "Mur5_optimized2014_5_materialInfo7.t"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture13.o" "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture13.ofu" "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture13.ofv" "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture13.rf" "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture13.reu" "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture13.rev" "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture13.vt1" "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture13.vt2" "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture13.vt3" "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture13.vc1" "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture13.ofs" "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.fs"
		;
connectAttr "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map.oa" "Mur5_optimized2014_5_bump2d7.bv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture14.o" "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture14.ofu" "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture14.ofv" "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture14.rf" "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture14.reu" "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture14.rev" "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture14.vt1" "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture14.vt2" "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture14.vt3" "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture14.vc1" "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture14.ofs" "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture15.o" "Mur5_optimized2014_5_lambert9_Flattened_Opacity.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture15.ofu" "Mur5_optimized2014_5_lambert9_Flattened_Opacity.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture15.ofv" "Mur5_optimized2014_5_lambert9_Flattened_Opacity.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture15.rf" "Mur5_optimized2014_5_lambert9_Flattened_Opacity.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture15.reu" "Mur5_optimized2014_5_lambert9_Flattened_Opacity.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture15.rev" "Mur5_optimized2014_5_lambert9_Flattened_Opacity.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture15.vt1" "Mur5_optimized2014_5_lambert9_Flattened_Opacity.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture15.vt2" "Mur5_optimized2014_5_lambert9_Flattened_Opacity.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture15.vt3" "Mur5_optimized2014_5_lambert9_Flattened_Opacity.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture15.vc1" "Mur5_optimized2014_5_lambert9_Flattened_Opacity.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture15.ofs" "Mur5_optimized2014_5_lambert9_Flattened_Opacity.fs"
		;
connectAttr "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.oc" "Mur5_optimized2014_5_lambert11.c"
		;
connectAttr "Mur5_optimized2014_5_bump2d8.o" "Mur5_optimized2014_5_lambert11.n";
connectAttr "Mur5_optimized2014_5_lambert11_Flattened_Opacity.ot" "Mur5_optimized2014_5_lambert11.it"
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.oc" "Mur5_optimized2014_5_lambert11.rc"
		;
connectAttr "Mur5_optimized2014_5_lambert11.oc" "Mur5_optimized2014_5_wallSG1.ss"
		;
connectAttr "Mur5_optimized2014_5_wallSG1.msg" "Mur5_optimized2014_5_materialInfo8.sg"
		;
connectAttr "Mur5_optimized2014_5_lambert11.msg" "Mur5_optimized2014_5_materialInfo8.m"
		;
connectAttr "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.msg" "Mur5_optimized2014_5_materialInfo8.t"
		 -na;
connectAttr "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map.oa" "Mur5_optimized2014_5_bump2d8.bv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture16.o" "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture16.ofu" "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture16.ofv" "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture16.rf" "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture16.reu" "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture16.rev" "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture16.vt1" "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture16.vt2" "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture16.vt3" "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture16.vc1" "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture16.ofs" "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.fs"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture17.o" "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture17.ofu" "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture17.ofv" "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture17.rf" "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture17.reu" "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture17.rev" "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture17.vt1" "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture17.vt2" "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture17.vt3" "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture17.vc1" "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture17.ofs" "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture18.o" "Mur5_optimized2014_5_lambert11_Flattened_Opacity.uv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture18.ofu" "Mur5_optimized2014_5_lambert11_Flattened_Opacity.ofu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture18.ofv" "Mur5_optimized2014_5_lambert11_Flattened_Opacity.ofv"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture18.rf" "Mur5_optimized2014_5_lambert11_Flattened_Opacity.rf"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture18.reu" "Mur5_optimized2014_5_lambert11_Flattened_Opacity.reu"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture18.rev" "Mur5_optimized2014_5_lambert11_Flattened_Opacity.rev"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture18.vt1" "Mur5_optimized2014_5_lambert11_Flattened_Opacity.vt1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture18.vt2" "Mur5_optimized2014_5_lambert11_Flattened_Opacity.vt2"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture18.vt3" "Mur5_optimized2014_5_lambert11_Flattened_Opacity.vt3"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture18.vc1" "Mur5_optimized2014_5_lambert11_Flattened_Opacity.vc1"
		;
connectAttr "Mur5_optimized2014_5_place2dTexture18.ofs" "Mur5_optimized2014_5_lambert11_Flattened_Opacity.fs"
		;
connectAttr "murBlockMini5_2014_place2dTexture12.o" "murBlockMini5_2014_lambert12_Flattened_Diffuse.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture12.ofu" "murBlockMini5_2014_lambert12_Flattened_Diffuse.ofu"
		;
connectAttr "murBlockMini5_2014_place2dTexture12.ofv" "murBlockMini5_2014_lambert12_Flattened_Diffuse.ofv"
		;
connectAttr "murBlockMini5_2014_place2dTexture12.rf" "murBlockMini5_2014_lambert12_Flattened_Diffuse.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture12.reu" "murBlockMini5_2014_lambert12_Flattened_Diffuse.reu"
		;
connectAttr "murBlockMini5_2014_place2dTexture12.rev" "murBlockMini5_2014_lambert12_Flattened_Diffuse.rev"
		;
connectAttr "murBlockMini5_2014_place2dTexture12.vt1" "murBlockMini5_2014_lambert12_Flattened_Diffuse.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture12.vt2" "murBlockMini5_2014_lambert12_Flattened_Diffuse.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture12.vt3" "murBlockMini5_2014_lambert12_Flattened_Diffuse.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture12.vc1" "murBlockMini5_2014_lambert12_Flattened_Diffuse.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture12.ofs" "murBlockMini5_2014_lambert12_Flattened_Diffuse.fs"
		;
connectAttr "murBlockMini5_2014_place2dTexture13.o" "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture13.ofu" "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map.ofu"
		;
connectAttr "murBlockMini5_2014_place2dTexture13.ofv" "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map.ofv"
		;
connectAttr "murBlockMini5_2014_place2dTexture13.rf" "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture13.reu" "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map.reu"
		;
connectAttr "murBlockMini5_2014_place2dTexture13.rev" "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map.rev"
		;
connectAttr "murBlockMini5_2014_place2dTexture13.vt1" "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture13.vt2" "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture13.vt3" "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture13.vc1" "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture13.ofs" "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map.fs"
		;
connectAttr "lambert14_Flattened_Diffuse_u1_v1.oc" "lambert14.c";
connectAttr "murBlockMini5_2014_bump2d5.o" "lambert14.n";
connectAttr "ReflectionMap.oc" "lambert14.rc";
connectAttr "lambert14.oc" "wallBlockMiniSG.ss";
connectAttr "wallBlockMiniSG.msg" "murBlockMini5_2014_materialInfo6.sg";
connectAttr "lambert14.msg" "murBlockMini5_2014_materialInfo6.m";
connectAttr "lambert14_Flattened_Diffuse_u1_v1.msg" "murBlockMini5_2014_materialInfo6.t"
		 -na;
connectAttr "murBlockMini5_2014_place2dTexture14.o" "lambert14_Flattened_Diffuse.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture14.ofu" "lambert14_Flattened_Diffuse.ofu"
		;
connectAttr "murBlockMini5_2014_place2dTexture14.ofv" "lambert14_Flattened_Diffuse.ofv"
		;
connectAttr "murBlockMini5_2014_place2dTexture14.rf" "lambert14_Flattened_Diffuse.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture14.reu" "lambert14_Flattened_Diffuse.reu"
		;
connectAttr "murBlockMini5_2014_place2dTexture14.rev" "lambert14_Flattened_Diffuse.rev"
		;
connectAttr "murBlockMini5_2014_place2dTexture14.vt1" "lambert14_Flattened_Diffuse.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture14.vt2" "lambert14_Flattened_Diffuse.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture14.vt3" "lambert14_Flattened_Diffuse.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture14.vc1" "lambert14_Flattened_Diffuse.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture14.ofs" "lambert14_Flattened_Diffuse.fs"
		;
connectAttr "lambert14_Flattened_NormalFBXASC032Map_u1_v1.oa" "murBlockMini5_2014_bump2d5.bv"
		;
connectAttr "murBlockMini5_2014_place2dTexture15.o" "lambert14_Flattened_NormalFBXASC032Map.uv"
		;
connectAttr "murBlockMini5_2014_place2dTexture15.ofu" "lambert14_Flattened_NormalFBXASC032Map.ofu"
		;
connectAttr "murBlockMini5_2014_place2dTexture15.ofv" "lambert14_Flattened_NormalFBXASC032Map.ofv"
		;
connectAttr "murBlockMini5_2014_place2dTexture15.rf" "lambert14_Flattened_NormalFBXASC032Map.rf"
		;
connectAttr "murBlockMini5_2014_place2dTexture15.reu" "lambert14_Flattened_NormalFBXASC032Map.reu"
		;
connectAttr "murBlockMini5_2014_place2dTexture15.rev" "lambert14_Flattened_NormalFBXASC032Map.rev"
		;
connectAttr "murBlockMini5_2014_place2dTexture15.vt1" "lambert14_Flattened_NormalFBXASC032Map.vt1"
		;
connectAttr "murBlockMini5_2014_place2dTexture15.vt2" "lambert14_Flattened_NormalFBXASC032Map.vt2"
		;
connectAttr "murBlockMini5_2014_place2dTexture15.vt3" "lambert14_Flattened_NormalFBXASC032Map.vt3"
		;
connectAttr "murBlockMini5_2014_place2dTexture15.vc1" "lambert14_Flattened_NormalFBXASC032Map.vc1"
		;
connectAttr "murBlockMini5_2014_place2dTexture15.ofs" "lambert14_Flattened_NormalFBXASC032Map.fs"
		;
connectAttr "place2dTexture19.o" "lambert14_Flattened_Diffuse_u1_v1.uv";
connectAttr "place2dTexture19.ofu" "lambert14_Flattened_Diffuse_u1_v1.ofu";
connectAttr "place2dTexture19.ofv" "lambert14_Flattened_Diffuse_u1_v1.ofv";
connectAttr "place2dTexture19.rf" "lambert14_Flattened_Diffuse_u1_v1.rf";
connectAttr "place2dTexture19.reu" "lambert14_Flattened_Diffuse_u1_v1.reu";
connectAttr "place2dTexture19.rev" "lambert14_Flattened_Diffuse_u1_v1.rev";
connectAttr "place2dTexture19.vt1" "lambert14_Flattened_Diffuse_u1_v1.vt1";
connectAttr "place2dTexture19.vt2" "lambert14_Flattened_Diffuse_u1_v1.vt2";
connectAttr "place2dTexture19.vt3" "lambert14_Flattened_Diffuse_u1_v1.vt3";
connectAttr "place2dTexture19.vc1" "lambert14_Flattened_Diffuse_u1_v1.vc1";
connectAttr "place2dTexture19.ofs" "lambert14_Flattened_Diffuse_u1_v1.fs";
connectAttr "place2dTexture20.o" "lambert14_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "place2dTexture20.ofu" "lambert14_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "place2dTexture20.ofv" "lambert14_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "place2dTexture20.rf" "lambert14_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "place2dTexture20.reu" "lambert14_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "place2dTexture20.rev" "lambert14_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "place2dTexture20.vt1" "lambert14_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "place2dTexture20.vt2" "lambert14_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "place2dTexture20.vt3" "lambert14_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "place2dTexture20.vc1" "lambert14_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "place2dTexture20.ofs" "lambert14_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "lambert15_Flattened_Diffuse_u1_v1.oc" "lambert15.c";
connectAttr "bump2d8.o" "lambert15.n";
connectAttr "ReflectionMap.oc" "lambert15.rc";
connectAttr "lambert15.oc" "wallBlockMiniSG1.ss";
connectAttr "wallBlockMiniSG1.msg" "materialInfo8.sg";
connectAttr "lambert15.msg" "materialInfo8.m";
connectAttr "lambert15_Flattened_Diffuse_u1_v1.msg" "materialInfo8.t" -na;
connectAttr "place2dTexture21.o" "lambert15_Flattened_Diffuse_u1_v1.uv";
connectAttr "place2dTexture21.ofu" "lambert15_Flattened_Diffuse_u1_v1.ofu";
connectAttr "place2dTexture21.ofv" "lambert15_Flattened_Diffuse_u1_v1.ofv";
connectAttr "place2dTexture21.rf" "lambert15_Flattened_Diffuse_u1_v1.rf";
connectAttr "place2dTexture21.reu" "lambert15_Flattened_Diffuse_u1_v1.reu";
connectAttr "place2dTexture21.rev" "lambert15_Flattened_Diffuse_u1_v1.rev";
connectAttr "place2dTexture21.vt1" "lambert15_Flattened_Diffuse_u1_v1.vt1";
connectAttr "place2dTexture21.vt2" "lambert15_Flattened_Diffuse_u1_v1.vt2";
connectAttr "place2dTexture21.vt3" "lambert15_Flattened_Diffuse_u1_v1.vt3";
connectAttr "place2dTexture21.vc1" "lambert15_Flattened_Diffuse_u1_v1.vc1";
connectAttr "place2dTexture21.ofs" "lambert15_Flattened_Diffuse_u1_v1.fs";
connectAttr "lambert15_Flattened_BumpFBXASC032Map_u1_v1.oa" "bump2d8.bv";
connectAttr "place2dTexture22.o" "lambert15_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "place2dTexture22.ofu" "lambert15_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "place2dTexture22.ofv" "lambert15_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "place2dTexture22.rf" "lambert15_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "place2dTexture22.reu" "lambert15_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "place2dTexture22.rev" "lambert15_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "place2dTexture22.vt1" "lambert15_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "place2dTexture22.vt2" "lambert15_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "place2dTexture22.vt3" "lambert15_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "place2dTexture22.vc1" "lambert15_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "place2dTexture22.ofs" "lambert15_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "place2dTexture23.o" "lambert15_Flattened_BumpFBXASC032Map_u1_v1.uv"
		;
connectAttr "place2dTexture23.ofu" "lambert15_Flattened_BumpFBXASC032Map_u1_v1.ofu"
		;
connectAttr "place2dTexture23.ofv" "lambert15_Flattened_BumpFBXASC032Map_u1_v1.ofv"
		;
connectAttr "place2dTexture23.rf" "lambert15_Flattened_BumpFBXASC032Map_u1_v1.rf"
		;
connectAttr "place2dTexture23.reu" "lambert15_Flattened_BumpFBXASC032Map_u1_v1.reu"
		;
connectAttr "place2dTexture23.rev" "lambert15_Flattened_BumpFBXASC032Map_u1_v1.rev"
		;
connectAttr "place2dTexture23.vt1" "lambert15_Flattened_BumpFBXASC032Map_u1_v1.vt1"
		;
connectAttr "place2dTexture23.vt2" "lambert15_Flattened_BumpFBXASC032Map_u1_v1.vt2"
		;
connectAttr "place2dTexture23.vt3" "lambert15_Flattened_BumpFBXASC032Map_u1_v1.vt3"
		;
connectAttr "place2dTexture23.vc1" "lambert15_Flattened_BumpFBXASC032Map_u1_v1.vc1"
		;
connectAttr "place2dTexture23.ofs" "lambert15_Flattened_BumpFBXASC032Map_u1_v1.fs"
		;
connectAttr "place2dTexture24.o" "lambert17_Flattened_BumpFBXASC032Map_u1_v1.uv"
		;
connectAttr "place2dTexture24.ofu" "lambert17_Flattened_BumpFBXASC032Map_u1_v1.ofu"
		;
connectAttr "place2dTexture24.ofv" "lambert17_Flattened_BumpFBXASC032Map_u1_v1.ofv"
		;
connectAttr "place2dTexture24.rf" "lambert17_Flattened_BumpFBXASC032Map_u1_v1.rf"
		;
connectAttr "place2dTexture24.reu" "lambert17_Flattened_BumpFBXASC032Map_u1_v1.reu"
		;
connectAttr "place2dTexture24.rev" "lambert17_Flattened_BumpFBXASC032Map_u1_v1.rev"
		;
connectAttr "place2dTexture24.vt1" "lambert17_Flattened_BumpFBXASC032Map_u1_v1.vt1"
		;
connectAttr "place2dTexture24.vt2" "lambert17_Flattened_BumpFBXASC032Map_u1_v1.vt2"
		;
connectAttr "place2dTexture24.vt3" "lambert17_Flattened_BumpFBXASC032Map_u1_v1.vt3"
		;
connectAttr "place2dTexture24.vc1" "lambert17_Flattened_BumpFBXASC032Map_u1_v1.vc1"
		;
connectAttr "place2dTexture24.ofs" "lambert17_Flattened_BumpFBXASC032Map_u1_v1.fs"
		;
connectAttr "file3.oc" "lambert18.c";
connectAttr "bump2d9.o" "lambert18.n";
connectAttr "lambert18.oc" "lambert18SG.ss";
connectAttr "lambert18SG.msg" "materialInfo9.sg";
connectAttr "lambert18.msg" "materialInfo9.m";
connectAttr "file3.msg" "materialInfo9.t" -na;
connectAttr "place2dTexture25.c" "file3.c";
connectAttr "place2dTexture25.tf" "file3.tf";
connectAttr "place2dTexture25.rf" "file3.rf";
connectAttr "place2dTexture25.mu" "file3.mu";
connectAttr "place2dTexture25.mv" "file3.mv";
connectAttr "place2dTexture25.s" "file3.s";
connectAttr "place2dTexture25.wu" "file3.wu";
connectAttr "place2dTexture25.wv" "file3.wv";
connectAttr "place2dTexture25.re" "file3.re";
connectAttr "place2dTexture25.of" "file3.of";
connectAttr "place2dTexture25.r" "file3.ro";
connectAttr "place2dTexture25.n" "file3.n";
connectAttr "place2dTexture25.vt1" "file3.vt1";
connectAttr "place2dTexture25.vt2" "file3.vt2";
connectAttr "place2dTexture25.vt3" "file3.vt3";
connectAttr "place2dTexture25.vc1" "file3.vc1";
connectAttr "place2dTexture25.o" "file3.uv";
connectAttr "place2dTexture25.ofs" "file3.fs";
connectAttr "place2dTexture26.c" "file4.c";
connectAttr "place2dTexture26.tf" "file4.tf";
connectAttr "place2dTexture26.rf" "file4.rf";
connectAttr "place2dTexture26.mu" "file4.mu";
connectAttr "place2dTexture26.mv" "file4.mv";
connectAttr "place2dTexture26.s" "file4.s";
connectAttr "place2dTexture26.wu" "file4.wu";
connectAttr "place2dTexture26.wv" "file4.wv";
connectAttr "place2dTexture26.re" "file4.re";
connectAttr "place2dTexture26.of" "file4.of";
connectAttr "place2dTexture26.r" "file4.ro";
connectAttr "place2dTexture26.n" "file4.n";
connectAttr "place2dTexture26.vt1" "file4.vt1";
connectAttr "place2dTexture26.vt2" "file4.vt2";
connectAttr "place2dTexture26.vt3" "file4.vt3";
connectAttr "place2dTexture26.vc1" "file4.vc1";
connectAttr "place2dTexture26.o" "file4.uv";
connectAttr "place2dTexture26.ofs" "file4.fs";
connectAttr "file4.oa" "bump2d9.bv";
connectAttr "lambert18_Flattened_Diffuse.oc" "lambert19.c";
connectAttr "bump2d10.o" "lambert19.n";
connectAttr "ReflectionMap.oc" "lambert19.rc";
connectAttr "lambert19.oc" "wallBlockMiniSG2.ss";
connectAttr "wallBlockMiniSG2.msg" "materialInfo10.sg";
connectAttr "lambert19.msg" "materialInfo10.m";
connectAttr "lambert18_Flattened_Diffuse.msg" "materialInfo10.t" -na;
connectAttr "place2dTexture27.o" "lambert18_Flattened_Diffuse.uv";
connectAttr "place2dTexture27.ofu" "lambert18_Flattened_Diffuse.ofu";
connectAttr "place2dTexture27.ofv" "lambert18_Flattened_Diffuse.ofv";
connectAttr "place2dTexture27.rf" "lambert18_Flattened_Diffuse.rf";
connectAttr "place2dTexture27.reu" "lambert18_Flattened_Diffuse.reu";
connectAttr "place2dTexture27.rev" "lambert18_Flattened_Diffuse.rev";
connectAttr "place2dTexture27.vt1" "lambert18_Flattened_Diffuse.vt1";
connectAttr "place2dTexture27.vt2" "lambert18_Flattened_Diffuse.vt2";
connectAttr "place2dTexture27.vt3" "lambert18_Flattened_Diffuse.vt3";
connectAttr "place2dTexture27.vc1" "lambert18_Flattened_Diffuse.vc1";
connectAttr "place2dTexture27.ofs" "lambert18_Flattened_Diffuse.fs";
connectAttr "lambert18_Flattened_BumpFBXASC032Map.oa" "bump2d10.bv";
connectAttr "place2dTexture28.o" "lambert18_Flattened_BumpFBXASC032Map.uv";
connectAttr "place2dTexture28.ofu" "lambert18_Flattened_BumpFBXASC032Map.ofu";
connectAttr "place2dTexture28.ofv" "lambert18_Flattened_BumpFBXASC032Map.ofv";
connectAttr "place2dTexture28.rf" "lambert18_Flattened_BumpFBXASC032Map.rf";
connectAttr "place2dTexture28.reu" "lambert18_Flattened_BumpFBXASC032Map.reu";
connectAttr "place2dTexture28.rev" "lambert18_Flattened_BumpFBXASC032Map.rev";
connectAttr "place2dTexture28.vt1" "lambert18_Flattened_BumpFBXASC032Map.vt1";
connectAttr "place2dTexture28.vt2" "lambert18_Flattened_BumpFBXASC032Map.vt2";
connectAttr "place2dTexture28.vt3" "lambert18_Flattened_BumpFBXASC032Map.vt3";
connectAttr "place2dTexture28.vc1" "lambert18_Flattened_BumpFBXASC032Map.vc1";
connectAttr "place2dTexture28.ofs" "lambert18_Flattened_BumpFBXASC032Map.fs";
connectAttr "lambert18_Flattened_Diffuse.oc" "lambert20.c";
connectAttr "bump2d11.o" "lambert20.n";
connectAttr "ReflectionMap.oc" "lambert20.rc";
connectAttr "lambert20.oc" "wallBlockMiniSG3.ss";
connectAttr "wallBlockMiniSG3.msg" "materialInfo11.sg";
connectAttr "lambert20.msg" "materialInfo11.m";
connectAttr "lambert18_Flattened_Diffuse.msg" "materialInfo11.t" -na;
connectAttr "lambert18_Flattened_BumpFBXASC032Map.oa" "bump2d11.bv";
connectAttr "file5.oc" "lambert21.c";
connectAttr "bump2d12.o" "lambert21.n";
connectAttr "lambert21.oc" "lambert21SG.ss";
connectAttr "wallBlockMiniShape.iog" "lambert21SG.dsm" -na;
connectAttr "lambert21SG.msg" "materialInfo12.sg";
connectAttr "lambert21.msg" "materialInfo12.m";
connectAttr "file5.msg" "materialInfo12.t" -na;
connectAttr "place2dTexture29.c" "file5.c";
connectAttr "place2dTexture29.tf" "file5.tf";
connectAttr "place2dTexture29.rf" "file5.rf";
connectAttr "place2dTexture29.mu" "file5.mu";
connectAttr "place2dTexture29.mv" "file5.mv";
connectAttr "place2dTexture29.s" "file5.s";
connectAttr "place2dTexture29.wu" "file5.wu";
connectAttr "place2dTexture29.wv" "file5.wv";
connectAttr "place2dTexture29.re" "file5.re";
connectAttr "place2dTexture29.of" "file5.of";
connectAttr "place2dTexture29.r" "file5.ro";
connectAttr "place2dTexture29.n" "file5.n";
connectAttr "place2dTexture29.vt1" "file5.vt1";
connectAttr "place2dTexture29.vt2" "file5.vt2";
connectAttr "place2dTexture29.vt3" "file5.vt3";
connectAttr "place2dTexture29.vc1" "file5.vc1";
connectAttr "place2dTexture29.o" "file5.uv";
connectAttr "place2dTexture29.ofs" "file5.fs";
connectAttr "place2dTexture30.c" "file6.c";
connectAttr "place2dTexture30.tf" "file6.tf";
connectAttr "place2dTexture30.rf" "file6.rf";
connectAttr "place2dTexture30.mu" "file6.mu";
connectAttr "place2dTexture30.mv" "file6.mv";
connectAttr "place2dTexture30.s" "file6.s";
connectAttr "place2dTexture30.wu" "file6.wu";
connectAttr "place2dTexture30.wv" "file6.wv";
connectAttr "place2dTexture30.re" "file6.re";
connectAttr "place2dTexture30.of" "file6.of";
connectAttr "place2dTexture30.r" "file6.ro";
connectAttr "place2dTexture30.n" "file6.n";
connectAttr "place2dTexture30.vt1" "file6.vt1";
connectAttr "place2dTexture30.vt2" "file6.vt2";
connectAttr "place2dTexture30.vt3" "file6.vt3";
connectAttr "place2dTexture30.vc1" "file6.vc1";
connectAttr "place2dTexture30.o" "file6.uv";
connectAttr "place2dTexture30.ofs" "file6.fs";
connectAttr "file6.oa" "bump2d12.bv";
connectAttr "hyperView1.msg" "nodeEditorPanel1Info.b[0]";
connectAttr "hyperLayout1.msg" "hyperView1.hl";
connectAttr "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:lambert8.c"
		;
connectAttr "mur_V2_22229_2014:bump2d1.o" "mur_V2_22229_2014:lambert8.n";
connectAttr "mur_V2_22229_2014:ReflectionMap.oc" "mur_V2_22229_2014:lambert8.rc"
		;
connectAttr "mur_V2_22229_2014:lambert8.oc" "mur_V2_22229_2014:polySurface33SG.ss"
		;
connectAttr "mur_V2_22229_2014:polySurface33SG.msg" "mur_V2_22229_2014:materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:lambert8.msg" "mur_V2_22229_2014:materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:place2dTexture1.o" "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture1.ofu" "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture1.ofv" "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture1.rf" "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture1.reu" "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture1.rev" "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:place2dTexture1.vt1" "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture1.vt2" "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture1.vt3" "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture1.vc1" "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture1.ofs" "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:bump2d1.bv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture2.o" "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture2.ofu" "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture2.ofv" "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture2.rf" "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture2.reu" "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture2.rev" "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:place2dTexture2.vt1" "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture2.vt2" "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture2.vt3" "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture2.vc1" "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture2.ofs" "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:place2dTexture3.o" "mur_V2_22229_2014:ReflectionMap.uv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture3.ofu" "mur_V2_22229_2014:ReflectionMap.ofu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture3.ofv" "mur_V2_22229_2014:ReflectionMap.ofv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture3.rf" "mur_V2_22229_2014:ReflectionMap.rf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture3.reu" "mur_V2_22229_2014:ReflectionMap.reu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture3.rev" "mur_V2_22229_2014:ReflectionMap.rev"
		;
connectAttr "mur_V2_22229_2014:place2dTexture3.vt1" "mur_V2_22229_2014:ReflectionMap.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture3.vt2" "mur_V2_22229_2014:ReflectionMap.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture3.vt3" "mur_V2_22229_2014:ReflectionMap.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture3.vc1" "mur_V2_22229_2014:ReflectionMap.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture3.ofs" "mur_V2_22229_2014:ReflectionMap.fs"
		;
connectAttr "mur_V2_22229_2014:file1.oc" "mur_V2_22229_2014:lambert9.c";
connectAttr "mur_V2_22229_2014:file1.ot" "mur_V2_22229_2014:lambert9.it";
connectAttr "mur_V2_22229_2014:bump2d2.o" "mur_V2_22229_2014:lambert9.n";
connectAttr "mur_V2_22229_2014:lambert9.oc" "mur_V2_22229_2014:lambert9SG.ss";
connectAttr "mur_V2_22229_2014:lambert9SG.msg" "mur_V2_22229_2014:materialInfo2.sg"
		;
connectAttr "mur_V2_22229_2014:lambert9.msg" "mur_V2_22229_2014:materialInfo2.m"
		;
connectAttr "mur_V2_22229_2014:file1.msg" "mur_V2_22229_2014:materialInfo2.t" -na
		;
connectAttr "mur_V2_22229_2014:place2dTexture4.c" "mur_V2_22229_2014:file1.c";
connectAttr "mur_V2_22229_2014:place2dTexture4.tf" "mur_V2_22229_2014:file1.tf";
connectAttr "mur_V2_22229_2014:place2dTexture4.rf" "mur_V2_22229_2014:file1.rf";
connectAttr "mur_V2_22229_2014:place2dTexture4.mu" "mur_V2_22229_2014:file1.mu";
connectAttr "mur_V2_22229_2014:place2dTexture4.mv" "mur_V2_22229_2014:file1.mv";
connectAttr "mur_V2_22229_2014:place2dTexture4.s" "mur_V2_22229_2014:file1.s";
connectAttr "mur_V2_22229_2014:place2dTexture4.wu" "mur_V2_22229_2014:file1.wu";
connectAttr "mur_V2_22229_2014:place2dTexture4.wv" "mur_V2_22229_2014:file1.wv";
connectAttr "mur_V2_22229_2014:place2dTexture4.re" "mur_V2_22229_2014:file1.re";
connectAttr "mur_V2_22229_2014:place2dTexture4.of" "mur_V2_22229_2014:file1.of";
connectAttr "mur_V2_22229_2014:place2dTexture4.r" "mur_V2_22229_2014:file1.ro";
connectAttr "mur_V2_22229_2014:place2dTexture4.n" "mur_V2_22229_2014:file1.n";
connectAttr "mur_V2_22229_2014:place2dTexture4.vt1" "mur_V2_22229_2014:file1.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture4.vt2" "mur_V2_22229_2014:file1.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture4.vt3" "mur_V2_22229_2014:file1.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture4.vc1" "mur_V2_22229_2014:file1.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture4.o" "mur_V2_22229_2014:file1.uv";
connectAttr "mur_V2_22229_2014:place2dTexture4.ofs" "mur_V2_22229_2014:file1.fs"
		;
connectAttr "mur_V2_22229_2014:place2dTexture5.c" "mur_V2_22229_2014:file2.c";
connectAttr "mur_V2_22229_2014:place2dTexture5.tf" "mur_V2_22229_2014:file2.tf";
connectAttr "mur_V2_22229_2014:place2dTexture5.rf" "mur_V2_22229_2014:file2.rf";
connectAttr "mur_V2_22229_2014:place2dTexture5.mu" "mur_V2_22229_2014:file2.mu";
connectAttr "mur_V2_22229_2014:place2dTexture5.mv" "mur_V2_22229_2014:file2.mv";
connectAttr "mur_V2_22229_2014:place2dTexture5.s" "mur_V2_22229_2014:file2.s";
connectAttr "mur_V2_22229_2014:place2dTexture5.wu" "mur_V2_22229_2014:file2.wu";
connectAttr "mur_V2_22229_2014:place2dTexture5.wv" "mur_V2_22229_2014:file2.wv";
connectAttr "mur_V2_22229_2014:place2dTexture5.re" "mur_V2_22229_2014:file2.re";
connectAttr "mur_V2_22229_2014:place2dTexture5.of" "mur_V2_22229_2014:file2.of";
connectAttr "mur_V2_22229_2014:place2dTexture5.r" "mur_V2_22229_2014:file2.ro";
connectAttr "mur_V2_22229_2014:place2dTexture5.n" "mur_V2_22229_2014:file2.n";
connectAttr "mur_V2_22229_2014:place2dTexture5.vt1" "mur_V2_22229_2014:file2.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture5.vt2" "mur_V2_22229_2014:file2.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture5.vt3" "mur_V2_22229_2014:file2.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture5.vc1" "mur_V2_22229_2014:file2.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture5.o" "mur_V2_22229_2014:file2.uv";
connectAttr "mur_V2_22229_2014:place2dTexture5.ofs" "mur_V2_22229_2014:file2.fs"
		;
connectAttr "mur_V2_22229_2014:file2.oa" "mur_V2_22229_2014:bump2d2.bv";
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8.c"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_bump2d1.o" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8.n"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap.oc" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8.rc"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8.oc" "mur_V2_22229_2014:Mur5_optimized2014_2_polySurface33SG.ss"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_polySurface33SG.msg" "mur_V2_22229_2014:Mur5_optimized2014_2_materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8.msg" "mur_V2_22229_2014:Mur5_optimized2014_2_materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:Mur5_optimized2014_2_materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture1.o" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture1.ofu" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture1.ofv" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture1.rf" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture1.reu" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture1.rev" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture1.vt1" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture1.vt2" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture1.vt3" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture1.vc1" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture1.ofs" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:Mur5_optimized2014_2_bump2d1.bv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture2.o" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture2.ofu" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture2.ofv" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture2.rf" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture2.reu" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture2.rev" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture2.vt1" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture2.vt2" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture2.vt3" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture2.vc1" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture2.ofs" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture3.o" "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap.uv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture3.ofu" "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap.ofu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture3.ofv" "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap.ofv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture3.rf" "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap.rf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture3.reu" "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap.reu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture3.rev" "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap.rev"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture3.vt1" "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap.vt1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture3.vt2" "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap.vt2"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture3.vt3" "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap.vt3"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture3.vc1" "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap.vc1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture3.ofs" "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap.fs"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_file1.oc" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert9.c"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_file1.ot" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert9.it"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_bump2d2.o" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert9.n"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_lambert9.oc" "mur_V2_22229_2014:Mur5_optimized2014_2_lambert9SG.ss"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_lambert9SG.msg" "mur_V2_22229_2014:Mur5_optimized2014_2_materialInfo2.sg"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_lambert9.msg" "mur_V2_22229_2014:Mur5_optimized2014_2_materialInfo2.m"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_file1.msg" "mur_V2_22229_2014:Mur5_optimized2014_2_materialInfo2.t"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.c" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.c"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.tf" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.tf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.rf" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.rf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.mu" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.mu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.mv" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.mv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.s" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.s"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.wu" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.wu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.wv" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.wv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.re" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.re"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.of" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.of"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.r" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.ro"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.n" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.n"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.vt1" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.vt1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.vt2" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.vt2"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.vt3" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.vt3"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.vc1" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.vc1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.o" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.uv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.ofs" "mur_V2_22229_2014:Mur5_optimized2014_2_file1.fs"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.c" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.c"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.tf" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.tf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.rf" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.rf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.mu" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.mu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.mv" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.mv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.s" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.s"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.wu" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.wu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.wv" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.wv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.re" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.re"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.of" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.of"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.r" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.ro"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.n" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.n"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.vt1" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.vt1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.vt2" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.vt2"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.vt3" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.vt3"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.vc1" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.vc1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.o" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.uv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.ofs" "mur_V2_22229_2014:Mur5_optimized2014_2_file2.fs"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_file2.oa" "mur_V2_22229_2014:Mur5_optimized2014_2_bump2d2.bv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8.c"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_bump2d1.o" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8.n"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.oc" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8.rc"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8.oc" "mur_V2_22229_2014:Mur5_optimized2014_4_polySurface33SG.ss"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_polySurface33SG.msg" "mur_V2_22229_2014:Mur5_optimized2014_4_materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8.msg" "mur_V2_22229_2014:Mur5_optimized2014_4_materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:Mur5_optimized2014_4_materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture1.o" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture1.ofu" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture1.ofv" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture1.rf" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture1.reu" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture1.rev" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture1.vt1" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture1.vt2" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture1.vt3" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture1.vc1" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture1.ofs" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:Mur5_optimized2014_4_bump2d1.bv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture2.o" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture2.ofu" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture2.ofv" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture2.rf" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture2.reu" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture2.rev" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture2.vt1" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture2.vt2" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture2.vt3" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture2.vc1" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture2.ofs" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture3.o" "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.uv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture3.ofu" "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.ofu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture3.ofv" "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.ofv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture3.rf" "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.rf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture3.reu" "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.reu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture3.rev" "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.rev"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture3.vt1" "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.vt1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture3.vt2" "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.vt2"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture3.vt3" "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.vt3"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture3.vc1" "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.vc1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture3.ofs" "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.fs"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_file1.oc" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert9.c"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_file1.ot" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert9.it"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_bump2d2.o" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert9.n"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_lambert9.oc" "mur_V2_22229_2014:Mur5_optimized2014_4_lambert9SG.ss"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_lambert9SG.msg" "mur_V2_22229_2014:Mur5_optimized2014_4_materialInfo2.sg"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_lambert9.msg" "mur_V2_22229_2014:Mur5_optimized2014_4_materialInfo2.m"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_file1.msg" "mur_V2_22229_2014:Mur5_optimized2014_4_materialInfo2.t"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.c" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.c"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.tf" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.tf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.rf" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.rf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.mu" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.mu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.mv" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.mv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.s" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.s"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.wu" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.wu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.wv" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.wv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.re" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.re"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.of" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.of"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.r" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.ro"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.n" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.n"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.vt1" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.vt1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.vt2" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.vt2"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.vt3" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.vt3"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.vc1" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.vc1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.o" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.uv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.ofs" "mur_V2_22229_2014:Mur5_optimized2014_4_file1.fs"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.c" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.c"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.tf" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.tf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.rf" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.rf"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.mu" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.mu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.mv" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.mv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.s" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.s"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.wu" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.wu"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.wv" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.wv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.re" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.re"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.of" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.of"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.r" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.ro"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.n" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.n"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.vt1" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.vt1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.vt2" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.vt2"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.vt3" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.vt3"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.vc1" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.vc1"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.o" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.uv"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.ofs" "mur_V2_22229_2014:Mur5_optimized2014_4_file2.fs"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_file2.oa" "mur_V2_22229_2014:Mur5_optimized2014_4_bump2d2.bv"
		;
connectAttr "mur_V2_22229_2014:lambert9_Flattened_Diffuse.oc" "mur_V2_22229_2014:lambert10.c"
		;
connectAttr "mur_V2_22229_2014:bump2d3.o" "mur_V2_22229_2014:lambert10.n";
connectAttr "mur_V2_22229_2014:lambert9_Flattened_Opacity.ot" "mur_V2_22229_2014:lambert10.it"
		;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.oc" "mur_V2_22229_2014:lambert10.rc"
		;
connectAttr "mur_V2_22229_2014:lambert10.oc" "mur_V2_22229_2014:wallSG.ss";
connectAttr "mur_V2_22229_2014:wallSG.msg" "mur_V2_22229_2014:materialInfo3.sg";
connectAttr "mur_V2_22229_2014:lambert10.msg" "mur_V2_22229_2014:materialInfo3.m"
		;
connectAttr "mur_V2_22229_2014:lambert9_Flattened_Diffuse.msg" "mur_V2_22229_2014:materialInfo3.t"
		 -na;
connectAttr "mur_V2_22229_2014:place2dTexture6.o" "mur_V2_22229_2014:lambert9_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture6.ofu" "mur_V2_22229_2014:lambert9_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture6.ofv" "mur_V2_22229_2014:lambert9_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture6.rf" "mur_V2_22229_2014:lambert9_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture6.reu" "mur_V2_22229_2014:lambert9_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture6.rev" "mur_V2_22229_2014:lambert9_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:place2dTexture6.vt1" "mur_V2_22229_2014:lambert9_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture6.vt2" "mur_V2_22229_2014:lambert9_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture6.vt3" "mur_V2_22229_2014:lambert9_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture6.vc1" "mur_V2_22229_2014:lambert9_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture6.ofs" "mur_V2_22229_2014:lambert9_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map.oa" "mur_V2_22229_2014:bump2d3.bv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture7.o" "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture7.ofu" "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture7.ofv" "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture7.rf" "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture7.reu" "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture7.rev" "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:place2dTexture7.vt1" "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture7.vt2" "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture7.vt3" "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture7.vc1" "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture7.ofs" "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:place2dTexture8.o" "mur_V2_22229_2014:lambert9_Flattened_Opacity.uv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture8.ofu" "mur_V2_22229_2014:lambert9_Flattened_Opacity.ofu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture8.ofv" "mur_V2_22229_2014:lambert9_Flattened_Opacity.ofv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture8.rf" "mur_V2_22229_2014:lambert9_Flattened_Opacity.rf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture8.reu" "mur_V2_22229_2014:lambert9_Flattened_Opacity.reu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture8.rev" "mur_V2_22229_2014:lambert9_Flattened_Opacity.rev"
		;
connectAttr "mur_V2_22229_2014:place2dTexture8.vt1" "mur_V2_22229_2014:lambert9_Flattened_Opacity.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture8.vt2" "mur_V2_22229_2014:lambert9_Flattened_Opacity.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture8.vt3" "mur_V2_22229_2014:lambert9_Flattened_Opacity.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture8.vc1" "mur_V2_22229_2014:lambert9_Flattened_Opacity.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture8.ofs" "mur_V2_22229_2014:lambert9_Flattened_Opacity.fs"
		;
connectAttr "mur_V2_22229_2014:lambert11_Flattened_Diffuse.oc" "mur_V2_22229_2014:lambert11.c"
		;
connectAttr "mur_V2_22229_2014:bump2d4.o" "mur_V2_22229_2014:lambert11.n";
connectAttr "mur_V2_22229_2014:lambert11_Flattened_Opacity.ot" "mur_V2_22229_2014:lambert11.it"
		;
connectAttr "mur_V2_22229_2014:ReflectionMap.oc" "mur_V2_22229_2014:lambert11.rc"
		;
connectAttr "mur_V2_22229_2014:lambert11.oc" "mur_V2_22229_2014:wallSG1.ss";
connectAttr "mur_V2_22229_2014:wallSG1.msg" "mur_V2_22229_2014:materialInfo4.sg"
		;
connectAttr "mur_V2_22229_2014:lambert11.msg" "mur_V2_22229_2014:materialInfo4.m"
		;
connectAttr "mur_V2_22229_2014:lambert11_Flattened_Diffuse.msg" "mur_V2_22229_2014:materialInfo4.t"
		 -na;
connectAttr "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map.oa" "mur_V2_22229_2014:bump2d4.bv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture9.o" "mur_V2_22229_2014:lambert11_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture9.ofu" "mur_V2_22229_2014:lambert11_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture9.ofv" "mur_V2_22229_2014:lambert11_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture9.rf" "mur_V2_22229_2014:lambert11_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture9.reu" "mur_V2_22229_2014:lambert11_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture9.rev" "mur_V2_22229_2014:lambert11_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:place2dTexture9.vt1" "mur_V2_22229_2014:lambert11_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture9.vt2" "mur_V2_22229_2014:lambert11_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture9.vt3" "mur_V2_22229_2014:lambert11_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture9.vc1" "mur_V2_22229_2014:lambert11_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture9.ofs" "mur_V2_22229_2014:lambert11_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:place2dTexture10.o" "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture10.ofu" "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture10.ofv" "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture10.rf" "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture10.reu" "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture10.rev" "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:place2dTexture10.vt1" "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture10.vt2" "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture10.vt3" "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture10.vc1" "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture10.ofs" "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:place2dTexture11.o" "mur_V2_22229_2014:lambert11_Flattened_Opacity.uv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture11.ofu" "mur_V2_22229_2014:lambert11_Flattened_Opacity.ofu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture11.ofv" "mur_V2_22229_2014:lambert11_Flattened_Opacity.ofv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture11.rf" "mur_V2_22229_2014:lambert11_Flattened_Opacity.rf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture11.reu" "mur_V2_22229_2014:lambert11_Flattened_Opacity.reu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture11.rev" "mur_V2_22229_2014:lambert11_Flattened_Opacity.rev"
		;
connectAttr "mur_V2_22229_2014:place2dTexture11.vt1" "mur_V2_22229_2014:lambert11_Flattened_Opacity.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture11.vt2" "mur_V2_22229_2014:lambert11_Flattened_Opacity.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture11.vt3" "mur_V2_22229_2014:lambert11_Flattened_Opacity.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture11.vc1" "mur_V2_22229_2014:lambert11_Flattened_Opacity.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture11.ofs" "mur_V2_22229_2014:lambert11_Flattened_Opacity.fs"
		;
connectAttr "mur_V2_22229_2014:lambert12_Flattened_Diffuse.oc" "mur_V2_22229_2014:lambert12.c"
		;
connectAttr "mur_V2_22229_2014:bump2d5.o" "mur_V2_22229_2014:lambert12.n";
connectAttr "mur_V2_22229_2014:lambert12_Flattened_Opacity.ot" "mur_V2_22229_2014:lambert12.it"
		;
connectAttr "mur_V2_22229_2014:ReflectionMap.oc" "mur_V2_22229_2014:lambert12.rc"
		;
connectAttr "mur_V2_22229_2014:lambert12.oc" "mur_V2_22229_2014:wallSG2.ss";
connectAttr "mur_V2_22229_2014:wallSG2.msg" "mur_V2_22229_2014:materialInfo5.sg"
		;
connectAttr "mur_V2_22229_2014:lambert12.msg" "mur_V2_22229_2014:materialInfo5.m"
		;
connectAttr "mur_V2_22229_2014:lambert12_Flattened_Diffuse.msg" "mur_V2_22229_2014:materialInfo5.t"
		 -na;
connectAttr "mur_V2_22229_2014:place2dTexture12.o" "mur_V2_22229_2014:lambert12_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture12.ofu" "mur_V2_22229_2014:lambert12_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture12.ofv" "mur_V2_22229_2014:lambert12_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture12.rf" "mur_V2_22229_2014:lambert12_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture12.reu" "mur_V2_22229_2014:lambert12_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture12.rev" "mur_V2_22229_2014:lambert12_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:place2dTexture12.vt1" "mur_V2_22229_2014:lambert12_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture12.vt2" "mur_V2_22229_2014:lambert12_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture12.vt3" "mur_V2_22229_2014:lambert12_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture12.vc1" "mur_V2_22229_2014:lambert12_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture12.ofs" "mur_V2_22229_2014:lambert12_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map.oa" "mur_V2_22229_2014:bump2d5.bv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture13.o" "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture13.ofu" "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture13.ofv" "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture13.rf" "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture13.reu" "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture13.rev" "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:place2dTexture13.vt1" "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture13.vt2" "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture13.vt3" "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture13.vc1" "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture13.ofs" "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:place2dTexture14.o" "mur_V2_22229_2014:lambert12_Flattened_Opacity.uv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture14.ofu" "mur_V2_22229_2014:lambert12_Flattened_Opacity.ofu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture14.ofv" "mur_V2_22229_2014:lambert12_Flattened_Opacity.ofv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture14.rf" "mur_V2_22229_2014:lambert12_Flattened_Opacity.rf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture14.reu" "mur_V2_22229_2014:lambert12_Flattened_Opacity.reu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture14.rev" "mur_V2_22229_2014:lambert12_Flattened_Opacity.rev"
		;
connectAttr "mur_V2_22229_2014:place2dTexture14.vt1" "mur_V2_22229_2014:lambert12_Flattened_Opacity.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture14.vt2" "mur_V2_22229_2014:lambert12_Flattened_Opacity.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture14.vt3" "mur_V2_22229_2014:lambert12_Flattened_Opacity.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture14.vc1" "mur_V2_22229_2014:lambert12_Flattened_Opacity.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture14.ofs" "mur_V2_22229_2014:lambert12_Flattened_Opacity.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert12.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d1.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert12.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert12.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert12.oc" "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert12.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture1.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture1.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture1.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture1.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture1.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture1.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture1.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture1.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture1.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture1.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture1.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:bump2d1.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture2.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture2.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture2.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture2.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture2.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture2.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture2.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture2.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture2.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture2.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture2.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture3.o" "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture3.ofu" "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture3.ofv" "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture3.rf" "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture3.reu" "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture3.rev" "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture3.vt1" "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture3.vt2" "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture3.vt3" "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture3.vc1" "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture3.ofs" "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert13.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d2.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert13.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert13.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert13.oc" "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG1.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG1.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo2.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert13.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo2.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo2.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture4.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture4.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture4.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture4.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture4.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture4.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture4.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture4.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture4.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture4.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture4.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:bump2d2.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture5.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture5.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture5.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture5.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture5.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture5.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture5.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture5.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture5.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture5.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture5.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert8.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d1.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert8.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert8.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert8.oc" "mur_V2_22229_2014:murPort4_2014_tri:polySurface33SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:polySurface33SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert8.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture1.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture1.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture1.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture1.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture1.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture1.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture1.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture1.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture1.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture1.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture1.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d1.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture2.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture2.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture2.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture2.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture2.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture2.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture2.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture2.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture2.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture2.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture2.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture3.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture3.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture3.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture3.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture3.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture3.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture3.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture3.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture3.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture3.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture3.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file1.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert9.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file1.ot" "mur_V2_22229_2014:murPort4_2014_tri:lambert9.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d2.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert9.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert9.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert9SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert9SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo2.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert9.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo2.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file1.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo2.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.c" "mur_V2_22229_2014:murPort4_2014_tri:file1.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.tf" "mur_V2_22229_2014:murPort4_2014_tri:file1.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.rf" "mur_V2_22229_2014:murPort4_2014_tri:file1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.mu" "mur_V2_22229_2014:murPort4_2014_tri:file1.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.mv" "mur_V2_22229_2014:murPort4_2014_tri:file1.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.s" "mur_V2_22229_2014:murPort4_2014_tri:file1.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.wu" "mur_V2_22229_2014:murPort4_2014_tri:file1.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.wv" "mur_V2_22229_2014:murPort4_2014_tri:file1.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.re" "mur_V2_22229_2014:murPort4_2014_tri:file1.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.of" "mur_V2_22229_2014:murPort4_2014_tri:file1.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.r" "mur_V2_22229_2014:murPort4_2014_tri:file1.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.n" "mur_V2_22229_2014:murPort4_2014_tri:file1.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.vt1" "mur_V2_22229_2014:murPort4_2014_tri:file1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.vt2" "mur_V2_22229_2014:murPort4_2014_tri:file1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.vt3" "mur_V2_22229_2014:murPort4_2014_tri:file1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.vc1" "mur_V2_22229_2014:murPort4_2014_tri:file1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.o" "mur_V2_22229_2014:murPort4_2014_tri:file1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.ofs" "mur_V2_22229_2014:murPort4_2014_tri:file1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.c" "mur_V2_22229_2014:murPort4_2014_tri:file2.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.tf" "mur_V2_22229_2014:murPort4_2014_tri:file2.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.rf" "mur_V2_22229_2014:murPort4_2014_tri:file2.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.mu" "mur_V2_22229_2014:murPort4_2014_tri:file2.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.mv" "mur_V2_22229_2014:murPort4_2014_tri:file2.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.s" "mur_V2_22229_2014:murPort4_2014_tri:file2.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.wu" "mur_V2_22229_2014:murPort4_2014_tri:file2.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.wv" "mur_V2_22229_2014:murPort4_2014_tri:file2.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.re" "mur_V2_22229_2014:murPort4_2014_tri:file2.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.of" "mur_V2_22229_2014:murPort4_2014_tri:file2.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.r" "mur_V2_22229_2014:murPort4_2014_tri:file2.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.n" "mur_V2_22229_2014:murPort4_2014_tri:file2.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.vt1" "mur_V2_22229_2014:murPort4_2014_tri:file2.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.vt2" "mur_V2_22229_2014:murPort4_2014_tri:file2.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.vt3" "mur_V2_22229_2014:murPort4_2014_tri:file2.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.vc1" "mur_V2_22229_2014:murPort4_2014_tri:file2.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.o" "mur_V2_22229_2014:murPort4_2014_tri:file2.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.ofs" "mur_V2_22229_2014:murPort4_2014_tri:file2.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file2.oa" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d2.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_bump2d1.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8.oc" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_polySurface33SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_polySurface33SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8.msg" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.ofu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.ofv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.rf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.reu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.rev" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.vt1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.vt2" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.vt3" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.vc1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.ofs" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_bump2d1.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.ofu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.ofv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.rf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.reu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.rev" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.vt1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.vt2" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.vt3" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.vc1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.ofs" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.ofu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.ofv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.rf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.reu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.rev" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.vt1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.vt2" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.vt3" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.vc1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.ofs" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.oc" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert9.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.ot" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert9.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_bump2d2.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert9.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert9.oc" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert9SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert9SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_materialInfo2.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert9.msg" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_materialInfo2.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.msg" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_materialInfo2.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.c" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.tf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.rf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.mu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.mv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.s" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.wu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.wv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.re" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.of" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.r" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.n" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.vt1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.vt2" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.vt3" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.vc1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.ofs" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.c" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.tf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.rf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.mu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.mv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.s" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.wu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.wv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.re" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.of" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.r" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.n" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.vt1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.vt2" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.vt3" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.vc1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.ofs" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.oa" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_bump2d2.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_bump2d1.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8.oc" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_polySurface33SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_polySurface33SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8.msg" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.ofu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.ofv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.rf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.reu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.rev" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.vt1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.vt2" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.vt3" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.vc1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.ofs" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_bump2d1.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.ofu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.ofv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.rf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.reu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.rev" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.vt1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.vt2" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.vt3" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.vc1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.ofs" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.ofu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.ofv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.rf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.reu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.rev" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.vt1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.vt2" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.vt3" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.vc1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.ofs" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.oc" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert9.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.ot" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert9.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_bump2d2.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert9.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert9.oc" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert9SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert9SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_materialInfo2.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert9.msg" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_materialInfo2.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.msg" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_materialInfo2.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.c" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.tf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.rf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.mu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.mv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.s" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.wu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.wv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.re" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.of" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.r" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.n" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.vt1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.vt2" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.vt3" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.vc1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.ofs" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.c" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.tf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.rf" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.mu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.mv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.s" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.wu" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.wv" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.re" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.of" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.r" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.n" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.vt1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.vt2" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.vt3" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.vc1" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.o" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.ofs" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.oa" "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_bump2d2.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert10.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d3.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert10.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity.ot" "mur_V2_22229_2014:murPort4_2014_tri:lambert10.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert10.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert10.oc" "mur_V2_22229_2014:murPort4_2014_tri:wallSG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallSG.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo3.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert10.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo3.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo3.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture6.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture6.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture6.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture6.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture6.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture6.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture6.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture6.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture6.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture6.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture6.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:bump2d3.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture7.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture7.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture7.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture7.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture7.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture7.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture7.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture7.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture7.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture7.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture7.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture8.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture8.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture8.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture8.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture8.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture8.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture8.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture8.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture8.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture8.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture8.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert11.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d4.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert11.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity.ot" "mur_V2_22229_2014:murPort4_2014_tri:lambert11.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert11.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert11.oc" "mur_V2_22229_2014:murPort4_2014_tri:wallSG1.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallSG1.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo4.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert11.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo4.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo4.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:bump2d4.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture9.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture9.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture9.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture9.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture9.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture9.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture9.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture9.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture9.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture9.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture9.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture10.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture10.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture10.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture10.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture10.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture10.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture10.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture10.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture10.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture10.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture10.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture11.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture11.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture11.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture11.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture11.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture11.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture11.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture11.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture11.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture11.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture11.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d5.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity.ot" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12.oc" "mur_V2_22229_2014:murPort4_2014_tri:wallSG2.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallSG2.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo5.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo5.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo5.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture12.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture12.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture12.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture12.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture12.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture12.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture12.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture12.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture12.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture12.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture12.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:bump2d5.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture13.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture13.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture13.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture13.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture13.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture13.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture13.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture13.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture13.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture13.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture13.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture14.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture14.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture14.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture14.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture14.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture14.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture14.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture14.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture14.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture14.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture14.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert16.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d6.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert16.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert16.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert16.oc" "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG2.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG2.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo6.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert16.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo6.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo6.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture15.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture15.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture15.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture15.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture15.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture15.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture15.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture15.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture15.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture15.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture15.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:murPort4_2014_tri:bump2d6.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture16.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture16.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture16.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture16.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture16.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture16.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture16.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture16.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture16.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture16.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture16.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert17.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d7.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert17.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert17.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert17.oc" "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG3.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG3.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo7.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert17.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo7.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo7.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture17.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture17.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture17.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture17.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture17.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture17.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture17.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture17.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture17.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture17.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture17.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:murPort4_2014_tri:bump2d7.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture18.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture18.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture18.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture18.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture18.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture18.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture18.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture18.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture18.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture18.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture18.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d1.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture1.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture1.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture1.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture1.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture1.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture1.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture1.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture1.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture1.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture1.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture1.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d1.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture2.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture2.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture2.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture2.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture2.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture2.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture2.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture2.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture2.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture2.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture2.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture3.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture3.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture3.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture3.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture3.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture3.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture3.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture3.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture3.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture3.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture3.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d2.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG1.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG1.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo2.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo2.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo2.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture4.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture4.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture4.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture4.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture4.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture4.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture4.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture4.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture4.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture4.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture4.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d2.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture5.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture5.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture5.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture5.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture5.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture5.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture5.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture5.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture5.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture5.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture5.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_bump2d1.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_polySurface33SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_polySurface33SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_bump2d1.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.ot" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_bump2d2.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo2.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo2.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_materialInfo2.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.c" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.tf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.mu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.mv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.s" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.wu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.wv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.re" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.of" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.r" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.n" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.c" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.tf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.mu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.mv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.s" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.wu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.wv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.re" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.of" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.r" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.n" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.oa" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_bump2d2.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d1.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_polySurface33SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_polySurface33SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d1.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.ot" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d2.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo2.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo2.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_materialInfo2.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.c" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.tf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.mu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.mv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.s" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.wu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.wv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.re" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.of" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.r" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.n" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.c" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.tf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.mu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.mv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.s" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.wu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.wv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.re" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.of" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.r" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.n" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.oa" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d2.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d1.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_polySurface33SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_polySurface33SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d1.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.ot" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d2.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo2.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo2.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_materialInfo2.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.c" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.tf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.mu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.mv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.s" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.wu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.wv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.re" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.of" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.r" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.n" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.c" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.tf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.mu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.mv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.s" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.wu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.wv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.re" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.of" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.r" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.n" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.oa" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d2.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert10.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d3.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert10.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.ot" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert10.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert10.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert10.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo3.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert10.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo3.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo3.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture6.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture6.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture6.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture6.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture6.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture6.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture6.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture6.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture6.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture6.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture6.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d3.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture7.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture7.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture7.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture7.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture7.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture7.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture7.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture7.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture7.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture7.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture7.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture8.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture8.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture8.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture8.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture8.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture8.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture8.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture8.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture8.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture8.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture8.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d4.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.ot" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG1.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG1.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo4.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo4.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo4.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d4.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture9.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture9.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture9.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture9.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture9.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture9.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture9.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture9.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture9.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture9.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture9.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture10.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture10.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture10.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture10.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture10.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture10.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture10.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture10.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture10.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture10.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture10.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture11.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture11.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture11.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture11.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture11.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture11.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture11.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture11.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture11.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture11.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture11.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d5.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.ot" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG2.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG2.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo5.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo5.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo5.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture12.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture12.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture12.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture12.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture12.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture12.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture12.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture12.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture12.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture12.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture12.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d5.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture13.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture13.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture13.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture13.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture13.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture13.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture13.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture13.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture13.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture13.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture13.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture14.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture14.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture14.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture14.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture14.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture14.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture14.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture14.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture14.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture14.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture14.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d6.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG2.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG2.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo6.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo6.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo6.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture15.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture15.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture15.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture15.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture15.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture15.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture15.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture15.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture15.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture15.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture15.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d6.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture16.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture16.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture16.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture16.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture16.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture16.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture16.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture16.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture16.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture16.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture16.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d7.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17.oc" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG3.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG3.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo7.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo7.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_materialInfo7.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture17.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture17.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture17.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture17.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture17.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture17.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture17.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture17.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture17.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture17.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture17.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d7.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture18.o" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture18.ofu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture18.ofv" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture18.rf" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture18.reu" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture18.rev" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture18.vt1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture18.vt2" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture18.vt3" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture18.vc1" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture18.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d3.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_polySurface33SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_polySurface33SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo3.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo3.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo3.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture6.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture6.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture6.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture6.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture6.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture6.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture6.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture6.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture6.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture6.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture6.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d3.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture7.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture7.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture7.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture7.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture7.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture7.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture7.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture7.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture7.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture7.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture7.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture8.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture8.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture8.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture8.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture8.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture8.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture8.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture8.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture8.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture8.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture8.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.ot" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d4.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo4.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo4.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo4.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.c" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.tf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.mu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.mv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.s" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.wu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.wv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.re" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.of" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.r" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.n" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.c" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.tf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.mu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.mv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.s" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.wu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.wv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.re" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.of" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.r" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.n" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.oa" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d4.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d1.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_polySurface33SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_polySurface33SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d1.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.ot" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d2.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo2.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo2.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_materialInfo2.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.c" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.tf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.mu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.mv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.s" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.wu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.wv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.re" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.of" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.r" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.n" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.c" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.tf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.mu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.mv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.s" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.wu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.wv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.re" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.of" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.r" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.n" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.oa" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d2.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d1.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_polySurface33SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_polySurface33SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.oa" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d1.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.ot" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d2.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo2.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo2.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_materialInfo2.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.c" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.tf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.mu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.mv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.s" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.wu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.wv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.re" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.of" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.r" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.n" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.c" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.tf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.mu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.mv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.s" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.wu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.wv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.re" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.of" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.r" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.n" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.oa" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d2.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert10.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d5.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert10.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.ot" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert10.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert10.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert10.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo5.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert10.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo5.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo5.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture11.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture11.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture11.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture11.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture11.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture11.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture11.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture11.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture11.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture11.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture11.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d5.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture12.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture12.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture12.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture12.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture12.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture12.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture12.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture12.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture12.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture12.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture12.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture13.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture13.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture13.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture13.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture13.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture13.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture13.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture13.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture13.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture13.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture13.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d6.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.ot" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG1.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG1.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo6.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo6.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo6.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d6.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture14.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture14.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture14.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture14.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture14.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture14.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture14.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture14.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture14.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture14.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture14.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture15.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture15.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture15.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture15.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture15.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture15.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture15.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture15.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture15.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture15.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture15.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture16.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture16.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture16.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture16.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture16.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture16.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture16.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture16.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture16.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture16.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture16.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert13.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d7.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert13.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.ot" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert13.it"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert13.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert13.oc" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG2.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG2.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo7.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert13.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo7.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.msg" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_materialInfo7.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture17.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture17.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture17.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture17.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture17.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture17.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture17.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture17.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture17.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture17.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture17.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d7.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture18.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture18.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture18.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture18.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture18.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture18.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture18.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture18.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture18.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture18.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture18.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture19.o" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture19.ofu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture19.ofv" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture19.rf" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture19.reu" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture19.rev" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture19.vt1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture19.vt2" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture19.vt3" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture19.vc1" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture19.ofs" "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1.oc" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat.msg" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1.msg" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.msg" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.oc" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1P2D.c" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1P2D.tf" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1P2D.rf" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1P2D.s" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1P2D.wu" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1P2D.wv" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1P2D.re" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1P2D.of" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1P2D.r" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1P2D.o" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1P2D.ofs" "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file3.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert18.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d8.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert18.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert18.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert18SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert18SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo8.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert18.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo8.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file3.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo8.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.c" "mur_V2_22229_2014:murPort4_2014_tri:file3.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.tf" "mur_V2_22229_2014:murPort4_2014_tri:file3.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.rf" "mur_V2_22229_2014:murPort4_2014_tri:file3.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.mu" "mur_V2_22229_2014:murPort4_2014_tri:file3.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.mv" "mur_V2_22229_2014:murPort4_2014_tri:file3.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.s" "mur_V2_22229_2014:murPort4_2014_tri:file3.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.wu" "mur_V2_22229_2014:murPort4_2014_tri:file3.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.wv" "mur_V2_22229_2014:murPort4_2014_tri:file3.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.re" "mur_V2_22229_2014:murPort4_2014_tri:file3.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.of" "mur_V2_22229_2014:murPort4_2014_tri:file3.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.r" "mur_V2_22229_2014:murPort4_2014_tri:file3.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.n" "mur_V2_22229_2014:murPort4_2014_tri:file3.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.vt1" "mur_V2_22229_2014:murPort4_2014_tri:file3.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.vt2" "mur_V2_22229_2014:murPort4_2014_tri:file3.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.vt3" "mur_V2_22229_2014:murPort4_2014_tri:file3.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.vc1" "mur_V2_22229_2014:murPort4_2014_tri:file3.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.o" "mur_V2_22229_2014:murPort4_2014_tri:file3.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.ofs" "mur_V2_22229_2014:murPort4_2014_tri:file3.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.c" "mur_V2_22229_2014:murPort4_2014_tri:file4.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.tf" "mur_V2_22229_2014:murPort4_2014_tri:file4.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.rf" "mur_V2_22229_2014:murPort4_2014_tri:file4.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.mu" "mur_V2_22229_2014:murPort4_2014_tri:file4.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.mv" "mur_V2_22229_2014:murPort4_2014_tri:file4.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.s" "mur_V2_22229_2014:murPort4_2014_tri:file4.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.wu" "mur_V2_22229_2014:murPort4_2014_tri:file4.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.wv" "mur_V2_22229_2014:murPort4_2014_tri:file4.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.re" "mur_V2_22229_2014:murPort4_2014_tri:file4.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.of" "mur_V2_22229_2014:murPort4_2014_tri:file4.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.r" "mur_V2_22229_2014:murPort4_2014_tri:file4.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.n" "mur_V2_22229_2014:murPort4_2014_tri:file4.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.vt1" "mur_V2_22229_2014:murPort4_2014_tri:file4.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.vt2" "mur_V2_22229_2014:murPort4_2014_tri:file4.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.vt3" "mur_V2_22229_2014:murPort4_2014_tri:file4.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.vc1" "mur_V2_22229_2014:murPort4_2014_tri:file4.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.o" "mur_V2_22229_2014:murPort4_2014_tri:file4.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.ofs" "mur_V2_22229_2014:murPort4_2014_tri:file4.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file4.oa" "mur_V2_22229_2014:murPort4_2014_tri:bump2d8.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert19.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d10.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert19.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.oc" "mur_V2_22229_2014:murPort4_2014_tri:lambert19.rc"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert19.oc" "mur_V2_22229_2014:murPort4_2014_tri:polySurface53SG.ss"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:polySurface53SG.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo9.sg"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert19.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo9.m"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.msg" "mur_V2_22229_2014:murPort4_2014_tri:materialInfo9.t"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture21.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture21.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture21.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture21.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture21.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture21.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture21.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture21.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture21.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture21.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture21.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.oa" "mur_V2_22229_2014:murPort4_2014_tri:bump2d9.bv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture22.o" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture22.ofu" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.ofu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture22.ofv" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.ofv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture22.rf" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture22.reu" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.reu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture22.rev" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.rev"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture22.vt1" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture22.vt2" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture22.vt3" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture22.vc1" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture22.ofs" "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:hyperView1.msg" "mur_V2_22229_2014:murPort4_2014_tri:nodeEditorPanel1Info.b[0]"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:hyperLayout1.msg" "mur_V2_22229_2014:murPort4_2014_tri:hyperView1.hl"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file5.msg" "mur_V2_22229_2014:murPort4_2014_tri:hyperLayout1.hyp[0].dn"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.msg" "mur_V2_22229_2014:murPort4_2014_tri:hyperLayout1.hyp[1].dn"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d10.msg" "mur_V2_22229_2014:murPort4_2014_tri:hyperLayout1.hyp[2].dn"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.c" "mur_V2_22229_2014:murPort4_2014_tri:file5.c"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.tf" "mur_V2_22229_2014:murPort4_2014_tri:file5.tf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.rf" "mur_V2_22229_2014:murPort4_2014_tri:file5.rf"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.mu" "mur_V2_22229_2014:murPort4_2014_tri:file5.mu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.mv" "mur_V2_22229_2014:murPort4_2014_tri:file5.mv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.s" "mur_V2_22229_2014:murPort4_2014_tri:file5.s"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.wu" "mur_V2_22229_2014:murPort4_2014_tri:file5.wu"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.wv" "mur_V2_22229_2014:murPort4_2014_tri:file5.wv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.re" "mur_V2_22229_2014:murPort4_2014_tri:file5.re"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.of" "mur_V2_22229_2014:murPort4_2014_tri:file5.of"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.r" "mur_V2_22229_2014:murPort4_2014_tri:file5.ro"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.n" "mur_V2_22229_2014:murPort4_2014_tri:file5.n"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.vt1" "mur_V2_22229_2014:murPort4_2014_tri:file5.vt1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.vt2" "mur_V2_22229_2014:murPort4_2014_tri:file5.vt2"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.vt3" "mur_V2_22229_2014:murPort4_2014_tri:file5.vt3"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.vc1" "mur_V2_22229_2014:murPort4_2014_tri:file5.vc1"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.o" "mur_V2_22229_2014:murPort4_2014_tri:file5.uv"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.ofs" "mur_V2_22229_2014:murPort4_2014_tri:file5.fs"
		;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file5.oa" "mur_V2_22229_2014:murPort4_2014_tri:bump2d10.bv"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1.oc" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat.ss"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat.msg" "mur_V2_22229_2014:MurV2exportFromZbrush:materialInfo1.sg"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1.msg" "mur_V2_22229_2014:MurV2exportFromZbrush:materialInfo1.m"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.msg" "mur_V2_22229_2014:MurV2exportFromZbrush:materialInfo1.t"
		 -na;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.oc" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1.c"
		;
connectAttr "mur_V2_22229_2014:bump2d6.o" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1.n"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1P2D.c" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.c"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1P2D.tf" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.tf"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1P2D.rf" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.rf"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1P2D.s" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.s"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1P2D.wu" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.wu"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1P2D.wv" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.wv"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1P2D.re" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.re"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1P2D.of" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.of"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1P2D.r" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.ro"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1P2D.o" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.uv"
		;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1P2D.ofs" "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.fs"
		;
connectAttr "mur_V2_22229_2014:place2dTexture15.c" "mur_V2_22229_2014:file3.c";
connectAttr "mur_V2_22229_2014:place2dTexture15.tf" "mur_V2_22229_2014:file3.tf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture15.rf" "mur_V2_22229_2014:file3.rf"
		;
connectAttr "mur_V2_22229_2014:place2dTexture15.mu" "mur_V2_22229_2014:file3.mu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture15.mv" "mur_V2_22229_2014:file3.mv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture15.s" "mur_V2_22229_2014:file3.s";
connectAttr "mur_V2_22229_2014:place2dTexture15.wu" "mur_V2_22229_2014:file3.wu"
		;
connectAttr "mur_V2_22229_2014:place2dTexture15.wv" "mur_V2_22229_2014:file3.wv"
		;
connectAttr "mur_V2_22229_2014:place2dTexture15.re" "mur_V2_22229_2014:file3.re"
		;
connectAttr "mur_V2_22229_2014:place2dTexture15.of" "mur_V2_22229_2014:file3.of"
		;
connectAttr "mur_V2_22229_2014:place2dTexture15.r" "mur_V2_22229_2014:file3.ro";
connectAttr "mur_V2_22229_2014:place2dTexture15.n" "mur_V2_22229_2014:file3.n";
connectAttr "mur_V2_22229_2014:place2dTexture15.vt1" "mur_V2_22229_2014:file3.vt1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture15.vt2" "mur_V2_22229_2014:file3.vt2"
		;
connectAttr "mur_V2_22229_2014:place2dTexture15.vt3" "mur_V2_22229_2014:file3.vt3"
		;
connectAttr "mur_V2_22229_2014:place2dTexture15.vc1" "mur_V2_22229_2014:file3.vc1"
		;
connectAttr "mur_V2_22229_2014:place2dTexture15.o" "mur_V2_22229_2014:file3.uv";
connectAttr "mur_V2_22229_2014:place2dTexture15.ofs" "mur_V2_22229_2014:file3.fs"
		;
connectAttr "mur_V2_22229_2014:file3.oa" "mur_V2_22229_2014:bump2d6.bv";
connectAttr "mur_V2_22229_2014:hyperView1.msg" "mur_V2_22229_2014:nodeEditorPanel1Info.b[0]"
		;
connectAttr "mur_V2_22229_2014:hyperLayout1.msg" "mur_V2_22229_2014:hyperView1.hl"
		;
connectAttr "wallBlockSG.pa" ":renderPartition.st" -na;
connectAttr "wallBlockSG1.pa" ":renderPartition.st" -na;
connectAttr "polySurface33SG.pa" ":renderPartition.st" -na;
connectAttr "lambert9SG.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_2_polySurface33SG.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_2_lambert9SG.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_4_polySurface33SG.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_4_lambert9SG.pa" ":renderPartition.st" -na;
connectAttr "wallSG.pa" ":renderPartition.st" -na;
connectAttr "wallSG1.pa" ":renderPartition.st" -na;
connectAttr "wallSG2.pa" ":renderPartition.st" -na;
connectAttr "wallBlockSG2.pa" ":renderPartition.st" -na;
connectAttr "wallBlockSG3.pa" ":renderPartition.st" -na;
connectAttr "murBlockMini5_2014_polySurface33SG.pa" ":renderPartition.st" -na;
connectAttr "murBlockMini5_2014_lambert9SG.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_polySurface33SG.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_lambert9SG.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_polySurface33SG1.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_lambert9SG1.pa" ":renderPartition.st" -na;
connectAttr "pasted__Mur5_optimized2014_lambert9SG1.pa" ":renderPartition.st" -na
		;
connectAttr "polySurface34SG.pa" ":renderPartition.st" -na;
connectAttr "polySurface34SG1.pa" ":renderPartition.st" -na;
connectAttr "polySurface34SG2.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_5_polySurface33SG.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_5_lambert9SG.pa" ":renderPartition.st" -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini5_2014_wallSG.pa" ":renderPartition.st" -na;
connectAttr "murBlockMini5_2014_wallSG1.pa" ":renderPartition.st" -na;
connectAttr "murBlockMini1_2014_polySurface33SG.pa" ":renderPartition.st" -na;
connectAttr "murBlockMini1_2014_lambert9SG.pa" ":renderPartition.st" -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_polySurface33SG1.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_lambert9SG1.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_lambert9SG1.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini1_2014_polySurface34SG.pa" ":renderPartition.st" -na;
connectAttr "murBlockMini1_2014_polySurface34SG1.pa" ":renderPartition.st" -na;
connectAttr "murBlockMini1_2014_polySurface34SG2.pa" ":renderPartition.st" -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "murBlockMini1_2014_wallSG.pa" ":renderPartition.st" -na;
connectAttr "murBlockMini1_2014_wallSG1.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_5_polySurface33SG1.pa" ":renderPartition.st" -na
		;
connectAttr "Mur5_optimized2014_5_lambert9SG1.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "Mur5_optimized2014_5_wallSG.pa" ":renderPartition.st" -na;
connectAttr "Mur5_optimized2014_5_wallSG1.pa" ":renderPartition.st" -na;
connectAttr "wallBlockMiniSG.pa" ":renderPartition.st" -na;
connectAttr "wallBlockMiniSG1.pa" ":renderPartition.st" -na;
connectAttr "lambert18SG.pa" ":renderPartition.st" -na;
connectAttr "wallBlockMiniSG2.pa" ":renderPartition.st" -na;
connectAttr "wallBlockMiniSG3.pa" ":renderPartition.st" -na;
connectAttr "lambert21SG.pa" ":renderPartition.st" -na;
connectAttr "mur_V2_22229_2014:polySurface33SG.pa" ":renderPartition.st" -na;
connectAttr "mur_V2_22229_2014:lambert9SG.pa" ":renderPartition.st" -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:wallSG.pa" ":renderPartition.st" -na;
connectAttr "mur_V2_22229_2014:wallSG1.pa" ":renderPartition.st" -na;
connectAttr "mur_V2_22229_2014:wallSG2.pa" ":renderPartition.st" -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG1.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallSG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallSG1.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallSG2.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG2.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:wallBlockSG3.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG1.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG1.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallSG2.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG2.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_wallBlockSG3.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_polySurface33SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG1.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_wallSG2.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert18SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:polySurface53SG.pa" ":renderPartition.st"
		 -na;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat.pa" ":renderPartition.st"
		 -na;
connectAttr "lambert12.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert13.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert8.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert9.msg" ":defaultShaderList1.s" -na;
connectAttr "Mur5_optimized2014_2_lambert8.msg" ":defaultShaderList1.s" -na;
connectAttr "Mur5_optimized2014_2_lambert9.msg" ":defaultShaderList1.s" -na;
connectAttr "Mur5_optimized2014_4_lambert8.msg" ":defaultShaderList1.s" -na;
connectAttr "Mur5_optimized2014_4_lambert9.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert10.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert11.msg" ":defaultShaderList1.s" -na;
connectAttr "mur22227_lambert12.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert16.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert17.msg" ":defaultShaderList1.s" -na;
connectAttr "murBlockMini5_2014_lambert12.msg" ":defaultShaderList1.s" -na;
connectAttr "murBlockMini5_2014_lambert8.msg" ":defaultShaderList1.s" -na;
connectAttr "murBlockMini5_2014_lambert9.msg" ":defaultShaderList1.s" -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murBlockMini5_2014_lambert10.msg" ":defaultShaderList1.s" -na;
connectAttr "murBlockMini5_2014_lambert11.msg" ":defaultShaderList1.s" -na;
connectAttr "murBlockMini1_2014_lambert12.msg" ":defaultShaderList1.s" -na;
connectAttr "murBlockMini1_2014_lambert8.msg" ":defaultShaderList1.s" -na;
connectAttr "murBlockMini1_2014_lambert9.msg" ":defaultShaderList1.s" -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "murBlockMini1_2014_lambert10.msg" ":defaultShaderList1.s" -na;
connectAttr "murBlockMini1_2014_lambert11.msg" ":defaultShaderList1.s" -na;
connectAttr "Mur5_optimized2014_5_lambert8.msg" ":defaultShaderList1.s" -na;
connectAttr "Mur5_optimized2014_5_lambert9.msg" ":defaultShaderList1.s" -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "Mur5_optimized2014_5_lambert10.msg" ":defaultShaderList1.s" -na;
connectAttr "Mur5_optimized2014_5_lambert11.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert14.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert15.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert18.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert19.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert20.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert21.msg" ":defaultShaderList1.s" -na;
connectAttr "mur_V2_22229_2014:lambert8.msg" ":defaultShaderList1.s" -na;
connectAttr "mur_V2_22229_2014:lambert9.msg" ":defaultShaderList1.s" -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:lambert10.msg" ":defaultShaderList1.s" -na;
connectAttr "mur_V2_22229_2014:lambert11.msg" ":defaultShaderList1.s" -na;
connectAttr "mur_V2_22229_2014:lambert12.msg" ":defaultShaderList1.s" -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert12.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert13.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert10.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert11.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert16.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert17.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert10.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert9.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert10.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert13.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert18.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert19.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1.msg" ":defaultShaderList1.s"
		 -na;
connectAttr "lambert12_Flattened_Diffuse.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert12_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "ReflectionMap.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert13_Flattened_Diffuse.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert13_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur22227_ReflectionMap.msg" ":defaultTextureList1.tx" -na;
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
connectAttr "mur22227_lambert12_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "lambert12_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "lambert12_Flattened_Opacity.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert16_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "lambert16_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "lambert17_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "lambert17_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_ReflectionMap.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "murBlockMini5_2014_file1.msg" ":defaultTextureList1.tx" -na;
connectAttr "murBlockMini5_2014_file2.msg" ":defaultTextureList1.tx" -na;
connectAttr "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_ReflectionMap.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "Mur5_optimized2014_file1.msg" ":defaultTextureList1.tx" -na;
connectAttr "Mur5_optimized2014_file2.msg" ":defaultTextureList1.tx" -na;
connectAttr "Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_ReflectionMap1.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "Mur5_optimized2014_file3.msg" ":defaultTextureList1.tx" -na;
connectAttr "Mur5_optimized2014_file4.msg" ":defaultTextureList1.tx" -na;
connectAttr "pasted__Mur5_optimized2014_file3.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "pasted__Mur5_optimized2014_file4.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "lambert1_Flattened_Diffuse.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert1_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_ReflectionMap.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "Mur5_optimized2014_5_file1.msg" ":defaultTextureList1.tx" -na;
connectAttr "Mur5_optimized2014_5_file2.msg" ":defaultTextureList1.tx" -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_lambert9_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_lambert9_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_lambert9_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_lambert11_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_lambert11_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_lambert11_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_ReflectionMap.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "murBlockMini1_2014_file1.msg" ":defaultTextureList1.tx" -na;
connectAttr "murBlockMini1_2014_file2.msg" ":defaultTextureList1.tx" -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_Diffuse_u1_v2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_lambert8_Flattened_NormalFBXASC032Map_u1_v2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_ReflectionMap1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_file3.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_file4.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_file3.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_file4.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_lambert1_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_lambert1_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_lambert9_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_lambert9_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_lambert9_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_lambert11_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_lambert11_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini1_2014_lambert11_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_lambert8_Flattened_Diffuse_u1_v2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_lambert8_Flattened_NormalFBXASC032Map_u1_v2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_ReflectionMap1.msg" ":defaultTextureList1.tx" 
		-na;
connectAttr "Mur5_optimized2014_5_file3.msg" ":defaultTextureList1.tx" -na;
connectAttr "Mur5_optimized2014_5_file4.msg" ":defaultTextureList1.tx" -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_lambert9_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_lambert9_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_lambert9_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_lambert11_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_lambert11_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "Mur5_optimized2014_5_lambert11_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_lambert12_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "murBlockMini5_2014_lambert12_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "lambert14_Flattened_Diffuse.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert14_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "lambert14_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "lambert14_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "lambert15_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx" -na
		;
connectAttr "lambert15_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "lambert15_Flattened_BumpFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "lambert17_Flattened_BumpFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "file3.msg" ":defaultTextureList1.tx" -na;
connectAttr "file4.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert18_Flattened_Diffuse.msg" ":defaultTextureList1.tx" -na;
connectAttr "lambert18_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "file5.msg" ":defaultTextureList1.tx" -na;
connectAttr "file6.msg" ":defaultTextureList1.tx" -na;
connectAttr "mur_V2_22229_2014:lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:ReflectionMap.msg" ":defaultTextureList1.tx" -na;
connectAttr "mur_V2_22229_2014:file1.msg" ":defaultTextureList1.tx" -na;
connectAttr "mur_V2_22229_2014:file2.msg" ":defaultTextureList1.tx" -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:lambert9_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:lambert9_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:lambert9_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:lambert11_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:lambert11_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:lambert11_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:lambert12_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:lambert12_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:lambert12_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert9_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert11_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert12_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_ReflectionMap1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1F.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file3.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file4.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_Diffuse.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:file5.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1F.msg" ":defaultTextureList1.tx"
		 -na;
connectAttr "mur_V2_22229_2014:file3.msg" ":defaultTextureList1.tx" -na;
connectAttr "place2dTexture1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture3.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture4.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture5.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "mur22227_place2dTexture1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "mur22227_bump2d1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "mur22227_place2dTexture2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "mur22227_place2dTexture3.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "mur22227_place2dTexture4.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "mur22227_place2dTexture5.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "mur22227_bump2d2.msg" ":defaultRenderUtilityList1.u" -na;
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
connectAttr "place2dTexture15.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d6.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture16.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture17.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d7.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture18.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murBlockMini5_2014_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_bump2d1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murBlockMini5_2014_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_bump2d2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "Mur5_optimized2014_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_bump2d1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "Mur5_optimized2014_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_bump2d2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "Mur5_optimized2014_place2dTexture6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_bump2d3.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "Mur5_optimized2014_place2dTexture7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_place2dTexture8.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_bump2d4.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "pasted__Mur5_optimized2014_place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "pasted__Mur5_optimized2014_place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "pasted__Mur5_optimized2014_bump2d4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_place2dTexture6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_bump2d3.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murBlockMini5_2014_place2dTexture7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_bump2d4.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "Mur5_optimized2014_5_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_bump2d1.msg" ":defaultRenderUtilityList1.u" -na
		;
connectAttr "Mur5_optimized2014_5_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_bump2d2.msg" ":defaultRenderUtilityList1.u" -na
		;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_2_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_Mur5_optimized2014_4_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_bump2d3.msg" ":defaultRenderUtilityList1.u" -na
		;
connectAttr "Mur5_optimized2014_5_place2dTexture7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_place2dTexture8.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_bump2d4.msg" ":defaultRenderUtilityList1.u" -na
		;
connectAttr "murBlockMini5_2014_place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_place2dTexture11.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_bump2d1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murBlockMini1_2014_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_bump2d2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_bump2d3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture8.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_bump2d4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_pasted__Mur5_optimized2014_bump2d4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_place2dTexture6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_bump2d3.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murBlockMini1_2014_place2dTexture7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_bump2d4.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_2_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_4_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_bump2d3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_place2dTexture7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_place2dTexture8.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_Mur5_optimized2014_5_bump2d4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini1_2014_place2dTexture11.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture8.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_bump2d5.msg" ":defaultRenderUtilityList1.u" -na
		;
connectAttr "Mur5_optimized2014_5_place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture11.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture12.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_bump2d6.msg" ":defaultRenderUtilityList1.u" -na
		;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_2_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_Mur5_optimized2014_4_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture13.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_bump2d7.msg" ":defaultRenderUtilityList1.u" -na
		;
connectAttr "Mur5_optimized2014_5_place2dTexture14.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture15.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_bump2d8.msg" ":defaultRenderUtilityList1.u" -na
		;
connectAttr "Mur5_optimized2014_5_place2dTexture16.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture17.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "Mur5_optimized2014_5_place2dTexture18.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_place2dTexture12.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_place2dTexture13.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_place2dTexture14.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "murBlockMini5_2014_bump2d5.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "murBlockMini5_2014_place2dTexture15.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "place2dTexture19.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture20.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture21.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d8.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture22.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture23.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture24.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture25.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture26.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d9.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture27.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d10.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture28.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d11.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture29.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture30.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "bump2d12.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "mur_V2_22229_2014:place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:bump2d1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "mur_V2_22229_2014:place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:bump2d2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_2_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:Mur5_optimized2014_4_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:place2dTexture6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:bump2d3.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "mur_V2_22229_2014:place2dTexture7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:place2dTexture8.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:bump2d4.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "mur_V2_22229_2014:place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:place2dTexture11.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:place2dTexture12.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:bump2d5.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "mur_V2_22229_2014:place2dTexture13.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:place2dTexture14.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_2_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:Mur5_optimized2014_4_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture8.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture11.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture12.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture13.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture14.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture15.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture16.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture17.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture18.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_mur22227_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture8.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture11.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture12.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture13.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture14.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture15.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture16.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture17.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_bump2d7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murBlock6_2014_place2dTexture18.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture8.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_2_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d1.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture3.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture4.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_place2dTexture5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_Mur5_optimized2014_4_bump2d2.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture11.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d5.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture12.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture13.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d6.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture14.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture15.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture16.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture17.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_bump2d7.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture18.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:mur22227_place2dTexture19.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:murPort2:defaultMat1P2D.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture19.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture20.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d8.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture21.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d9.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture22.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:place2dTexture23.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:murPort4_2014_tri:bump2d10.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:MurV2exportFromZbrush:defaultMat1P2D.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:place2dTexture15.msg" ":defaultRenderUtilityList1.u"
		 -na;
connectAttr "mur_V2_22229_2014:bump2d6.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
dataStructure -fmt "raw" -as "name=externalContentTable:string=node:string=key:string=upath:uint32=upathcrc:string=rpath:string=roles";
applyMetadata -fmt "raw" -v "channel\nname externalContentTable\nstream\nname v1.0\nindexType numeric\nstructure externalContentTable\n0\n\"lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n1\n\"lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n2\n\"ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n3\n\"file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n4\n\"file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n5\n\"Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n6\n\"Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n7\n\"Mur5_optimized2014_2_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n8\n\"Mur5_optimized2014_2_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n9\n\"Mur5_optimized2014_2_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n10\n\"Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n11\n\"Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n12\n\"Mur5_optimized2014_4_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n13\n\"Mur5_optimized2014_4_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n14\n\"Mur5_optimized2014_4_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n15\n\"lambert9_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n16\n\"lambert9_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n17\n\"lambert9_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n18\n\"lambert11_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n19\n\"lambert11_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n20\n\"lambert11_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n21\n\"lambert12_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush1Text.png\" 2904893610 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush1Text.png\" \"sourceImages\"\n22\n\"lambert12_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush1Norm.png\" 675646610 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush1Norm.png\" \"sourceImages\"\n23\n\"lambert12_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n24\n\"murPort4_2014_tri:lambert12_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" 4288469390 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" \"sourceImages\"\n25\n\"murPort4_2014_tri:lambert12_Flattened_NormalFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" 2238725887 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" \"sourceImages\"\n26\n\"murPort4_2014_tri:ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n27\n\"murPort4_2014_tri:lambert13_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" 4288469390 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" \"sourceImages\"\n28\n\"murPort4_2014_tri:lambert13_Flattened_NormalFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" 2238725887 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" \"sourceImages\"\n29\n\"murPort4_2014_tri:lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n30\n\"murPort4_2014_tri:lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n31\n\"murPort4_2014_tri:mur22227_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n32\n\"murPort4_2014_tri:file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n33\n\"murPort4_2014_tri:file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n34\n\"murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n35\n\"murPort4_2014_tri:Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n36\n\"murPort4_2014_tri:Mur5_optimized2014_2_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n37\n\"murPort4_2014_tri:Mur5_optimized2014_2_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n38\n\"murPort4_2014_tri:Mur5_optimized2014_2_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n39\n\"murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n40\n\"murPort4_2014_tri:Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n41\n\"murPort4_2014_tri:Mur5_optimized2014_4_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n42\n\"murPort4_2014_tri:Mur5_optimized2014_4_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n43\n\"murPort4_2014_tri:Mur5_optimized2014_4_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n44\n\"murPort4_2014_tri:lambert9_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n45\n\"murPort4_2014_tri:lambert9_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n46\n\"murPort4_2014_tri:lambert9_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n47\n\"murPort4_2014_tri:lambert11_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n48\n\"murPort4_2014_tri:lambert11_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n49\n\"murPort4_2014_tri:lambert11_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n50\n\"murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n51\n\"murPort4_2014_tri:lambert12_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n52\n\"murPort4_2014_tri:lambert12_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n53\n\"murPort4_2014_tri:lambert16_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" 1636531969 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" \"sourceImages\"\n54\n\"murPort4_2014_tri:lambert16_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal.png\" 3525560328 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal.png\" \"sourceImages\"\n55\n\"murPort4_2014_tri:lambert17_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" 1636531969 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" \"sourceImages\"\n56\n\"murPort4_2014_tri:lambert17_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal_u1_v1.png\" 2170994057 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal_u1_v1.png\" \"sourceImages\"\n57\n\"murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" 4288469390 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" \"sourceImages\"\n58\n\"murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_NormalFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" 2238725887 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" \"sourceImages\"\n59\n\"murPort4_2014_tri:murBlock6_2014_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n60\n\"murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" 4288469390 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512.png\" \"sourceImages\"\n61\n\"murPort4_2014_tri:murBlock6_2014_lambert13_Flattened_NormalFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" 2238725887 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/DefaultNormal/defualtNormal.png\" \"sourceImages\"\n62\n\"murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n63\n\"murPort4_2014_tri:murBlock6_2014_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n64\n\"murPort4_2014_tri:murBlock6_2014_mur22227_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n65\n\"murPort4_2014_tri:murBlock6_2014_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n66\n\"murPort4_2014_tri:murBlock6_2014_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n67\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n68\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n69\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n70\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n71\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_2_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n72\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n73\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n74\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n75\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n76\n\"murPort4_2014_tri:murBlock6_2014_Mur5_optimized2014_4_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n77\n\"murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n78\n\"murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n79\n\"murPort4_2014_tri:murBlock6_2014_lambert9_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n80\n\"murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n81\n\"murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n82\n\"murPort4_2014_tri:murBlock6_2014_lambert11_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n83\n\"murPort4_2014_tri:murBlock6_2014_mur22227_lambert12_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n84\n\"murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n85\n\"murPort4_2014_tri:murBlock6_2014_lambert12_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n86\n\"murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" 1636531969 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" \"sourceImages\"\n87\n\"murPort4_2014_tri:murBlock6_2014_lambert16_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal.png\" 3525560328 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal.png\" \"sourceImages\"\n88\n\"murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" 1636531969 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/MurBlock/murBlockTexture512_u1_v1.png\" \"sourceImages\"\n89\n\"murPort4_2014_tri:murBlock6_2014_lambert17_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal_u1_v1.png\" 2170994057 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurBlock/MurBlockNormal_u1_v1.png\" \"sourceImages\"\n90\n\"murPort4_2014_tri:mur22227_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n91\n\"murPort4_2014_tri:mur22227_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n92\n\"murPort4_2014_tri:mur22227_ReflectionMap1\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n93\n\"murPort4_2014_tri:mur22227_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n94\n\"murPort4_2014_tri:mur22227_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n95\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n96\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_2_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n97\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_2_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n98\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n99\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_2_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n100\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_Diffuse_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" 1666987212 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureTopp2_u1_v1.tif\" \"sourceImages\"\n101\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_4_lambert8_Flattened_NormalFBXASC032Map_u1_v1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" 2870153694 \"C:/Users/Gustav/Documents/Mudbox/2015-x64/data/MurTextureToppNormal2_u1_v1.tif\" \"sourceImages\"\n102\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_4_ReflectionMap\" \"fileTextureName\" \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" 1676409309 \"C:/Program Files/Autodesk/Mudbox 2015/Textures/Lightprobes/horizon.exr\" \"sourceImages\"\n103\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n104\n\"murPort4_2014_tri:mur22227_Mur5_optimized2014_4_file2\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n105\n\"murPort4_2014_tri:mur22227_lambert9_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n106\n\"murPort4_2014_tri:mur22227_lambert9_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" 3042558891 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/New folder/__murTest_u3_v1.png\" \"sourceImages\"\n107\n\"murPort4_2014_tri:mur22227_lambert9_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n108\n\"murPort4_2014_tri:mur22227_lambert11_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n109\n\"murPort4_2014_tri:mur22227_lambert11_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n110\n\"murPort4_2014_tri:mur22227_lambert11_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n111\n\"murPort4_2014_tri:mur22227_lambert12_Flattened_Diffuse1\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" 2117110312 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024.png\" \"sourceImages\"\n112\n\"murPort4_2014_tri:mur22227_lambert12_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" 2165016054 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/Mur/mur1024x1024Normal.png\" \"sourceImages\"\n113\n\"murPort4_2014_tri:mur22227_lambert12_Flattened_Opacity\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" 324490466 \"C:/Users/Gustav/Documents/StortSpelProjekt/Texturer/_/Texture2.png\" \"sourceImages\"\n114\n\"murPort4_2014_tri:murPort2:defaultMat1F\" \"fileTextureName\" \"murPort2.bmp\" 1882535258 \"\" \"sourceImages\"\n115\n\"murPort4_2014_tri:file3\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort2_texture.png\" 3903194042 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort2_texture.png\" \"sourceImages\"\n116\n\"murPort4_2014_tri:file4\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort2_normal.png\" 396662271 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort2_normal.png\" \"sourceImages\"\n117\n\"murPort4_2014_tri:lambert18_Flattened_Diffuse\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort5_texture.png\" 2513765858 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort5_texture.png\" \"sourceImages\"\n118\n\"murPort4_2014_tri:lambert18_Flattened_BumpFBXASC032Map\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort4_normal.png\" 4170788895 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort4_normal.png\" \"sourceImages\"\n119\n\"murPort4_2014_tri:file5\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort4_normal.png\" 4170788895 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurPort/murPort4_normal.png\" \"sourceImages\"\n120\n\"MurV2exportFromZbrush:defaultMat1F\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush3Text.png\" 2211643436 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush3Text.png\" \"sourceImages\"\n121\n\"file3\" \"fileTextureName\" \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush3Norm.png\" 112436244 \"C:/Users/Gustav/Documents/StortSpelProjekt/Modeller/Mur/MurStandard/murZbrush3Norm.png\" \"sourceImages\"\nendStream\nendChannel\nendAssociations\n" 
		-scn;
// End of murBlockMiniV2_2014_2.ma
