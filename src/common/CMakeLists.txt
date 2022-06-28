include(common)
include(libs/unix)

set(Base_src
    "Base/Sequence.cpp"
    "Base/Sequence.h"
    "Base/Benchmark.cpp"
    "Base/Benchmark.h"
    "Base/ImGuiHelper.cpp"
    "Base/ImGuiHelper.h"
)

set(shader_compiler_src
    "Base/ShaderCompiler.cpp"
    "Base/ShaderCompiler.h"
    "Base/ShaderCompilerCache.cpp"
    "Base/ShaderCompilerCache.h"
    "Base/DXCHelper.cpp"
    "Base/DXCHelper.h"
)

set(GLTF_src
    "GLTF/GltfStructures.h"
    "GLTF/GltfCommon.cpp"
    "GLTF/GltfCommon.h"
    "GLTF/GltfPbrMaterial.cpp"
    "GLTF/GltfPbrMaterial.h"
    "GLTF/GltfHelpers.cpp"
    "GLTF/GltfHelpers.h"
)

file(GLOB_RECURSE Misc_src
    "Misc/*.cpp"
    "Misc/*.h"
)

set(FidelityFX_src
    ${CMAKE_CURRENT_SOURCE_DIR}/FidelityFX/include/gpu/ffx_common_types.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FidelityFX/include/gpu/ffx_core.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FidelityFX/include/gpu/ffx_core_cpu.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FidelityFX/include/gpu/ffx_lpm.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FidelityFX/include/gpu/ffx_core_hlsl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FidelityFX/include/gpu/ffx_core_glsl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FidelityFX/include/gpu/ffx_core_gpu_common.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FidelityFX/include/gpu/ffx_core_gpu_common_half.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FidelityFX/include/gpu/ffx_core_portability.h
)

#add_library (Cauldron_Common STATIC ${Base_src} ${GLTF_src} ${Misc_src} ${shader_compiler_src} ${media_src})
 add_library (Cauldron_Common STATIC stdafx.cpp ${media_src}
   "Base/Sequence.cpp"
   "Base/ShaderCompilerCache.cpp"
   "Misc/Misc.cpp"
	 )
target_link_libraries (Cauldron_Common PUBLIC NJSON STB DXC Shcore)
target_include_directories (Cauldron_Common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(media_src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../media/BrdfLut.dds
)

copyTargetCommand("${media_src}" ${CMAKE_HOME_DIRECTORY}/bin copied_common_media_src)
copyTargetCommand("${FidelityFX_src}" ${CMAKE_HOME_DIRECTORY}/bin/ShaderLibVK copied_vk_FidelityFX_src)
copyTargetCommand("${FidelityFX_src}" ${CMAKE_HOME_DIRECTORY}/bin/ShaderLibDX copied_dx_FidelityFX_src)
add_dependencies (Cauldron_Common copied_common_media_src copied_vk_FidelityFX_src copied_dx_FidelityFX_src)

source_group("Base"         FILES ${Base_src})
source_group("GLTF"         FILES ${GLTF_src})
source_group("Misc"         FILES ${Misc_src})
source_group("SC"           FILES ${shader_compiler_src})

set_source_files_properties(${FidelityFX_src} PROPERTIES VS_TOOL_OVERRIDE "Text")
