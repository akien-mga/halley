cmake_minimum_required (VERSION 3.10)

project (halley-editor)

SET(HALLEY_MONOLITHIC 1)

set (editor_sources
	"prec.cpp"

	"src/editor_root_stage.cpp"
	"src/halley_editor.cpp"
	"src/preferences.cpp"

	"src/assets/animation_editor.cpp"
	"src/assets/asset_editor_window.cpp"
	"src/assets/asset_editor.cpp"
	"src/assets/assets_browser.cpp"
	"src/assets/asset_browser_tabs.cpp"
	"src/assets/metadata_editor.cpp"
	"src/assets/new_asset_window.cpp"
	"src/assets/prefab_editor.cpp"

	"src/assets/graph/graph_editor.cpp"
	"src/assets/graph/render_graph_editor.cpp"
	"src/assets/graph/ui_graph_node.cpp"
	
	"src/project/core_api_wrapper.cpp"

	"src/scene/choose_asset_window.cpp"
	"src/scene/entity_editor.cpp"
	"src/scene/entity_editor_factories.cpp"
	"src/scene/entity_icons.cpp"
	"src/scene/entity_list.cpp"
	"src/scene/scene_editor_canvas.cpp"
	"src/scene/scene_editor_game_bridge.cpp"
	"src/scene/scene_editor_gizmo_collection.cpp"
	"src/scene/scene_editor_window.cpp"
	"src/scene/undo_stack.cpp"

	"src/scene/gizmos/scripting_gizmo.cpp"
	"src/scene/gizmos/selected_bounds_gizmo.cpp"
	"src/scene/gizmos/selection_box_gizmo.cpp"
	"src/scene/gizmos/translate_gizmo.cpp"

	"src/ui/console_window.cpp"
	"src/ui/ecs_window.cpp"
	"src/ui/editor_settings_window.cpp"
	"src/ui/editor_ui_factory.cpp"
	"src/ui/game_properties_window.cpp"
	"src/ui/load_project_window.cpp"
	"src/ui/project_window.cpp"
	"src/ui/scroll_background.cpp"
	"src/ui/select_asset_widget.cpp"
	"src/ui/task_details.cpp"
	"src/ui/task_display.cpp"
	"src/ui/taskbar.cpp"
	"src/ui/toolbar.cpp"

	"../../../gen/cpp/registry.cpp"
	)

set (editor_headers
	"prec.h"
	"src/editor_root_stage.h"
	"src/halley_editor.h"
	"src/preferences.h"

	"src/assets/animation_editor.h"
	"src/assets/asset_editor_window.h"
	"src/assets/asset_editor.h"
	"src/assets/assets_browser.h"
	"src/assets/asset_browser_tabs.h"
	"src/assets/metadata_editor.h"
	"src/assets/new_asset_window.h"
	"src/assets/prefab_editor.h"

	"src/assets/graph/graph_editor.h"
	"src/assets/graph/render_graph_editor.h"
	"src/assets/graph/ui_graph_node.h"

	"src/project/core_api_wrapper.h"

	"src/scene/choose_asset_window.h"
	"src/scene/entity_editor.h"
	"src/scene/entity_editor_factories.h"
	"src/scene/entity_icons.h"
	"src/scene/entity_list.h"
	"src/scene/scene_editor_canvas.h"
	"src/scene/scene_editor_game_bridge.h"
	"src/scene/scene_editor_gizmo_collection.h"
	"src/scene/scene_editor_window.h"
	"src/scene/undo_stack.h"

	"src/scene/gizmos/scripting_gizmo.h"
	"src/scene/gizmos/selected_bounds_gizmo.h"
	"src/scene/gizmos/selection_box_gizmo.h"
	"src/scene/gizmos/translate_gizmo.h"
	
	"src/ui/console_window.h"
	"src/ui/ecs_window.h"
	"src/ui/editor_settings_window.h"
	"src/ui/editor_ui_factory.h"
	"src/ui/game_properties_window.h"
	"src/ui/load_project_window.h"
	"src/ui/project_window.h"
	"src/ui/scroll_background.h"
	"src/ui/select_asset_widget.h"
	"src/ui/task_details.h"
	"src/ui/task_display.h"
	"src/ui/taskbar.h"
	"src/ui/toolbar.h"
	)

if (MSVC)
	set (editor_headers
		${editor_headers}
		"res/halley-editor.rc"
		"res/resource.h"
		"res/halley.ico"
	)
endif ()

set (editor_gen_definitions
	)


if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(EXTRA_LIBS bz2 z halley-metal)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set(EXTRA_LIBS pthread)
endif()

include_directories(${FREETYPE_INCLUDE_DIR} "../tools/include")

halleyProjectCodegen(halley-editor "${editor_sources}" "${editor_headers}" "${editor_gen_definitions}" ${CMAKE_CURRENT_SOURCE_DIR}/../../../bin)
add_dependencies(halley-editor halley-cmd halley-core halley-net halley-sdl halley-opengl)
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	add_dependencies(halley-editor halley-metal)
endif()

get_property(deps GLOBAL PROPERTY halley_external_plugin_dependencies)
if (NOT ("${deps}" STREQUAL ""))
    separate_arguments(deps)
    add_dependencies(halley-editor ${deps})
endif()

target_link_libraries (halley-editor
        halley-tools
        ${FREETYPE_LIBRARIES}
        ${YAMLCPP_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
		${EXTRA_LIBS}
		${ShaderConductor_LIBRARY}
        )
