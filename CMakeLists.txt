cmake_minimum_required(VERSION 3.22)
project(AUDIO_PLUGIN_EXAMPLE VERSION 0.0.1)

include(FetchContent)
FetchContent_Declare(JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG 8.0.12
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(JUCE)

juce_add_plugin(AudioPluginExample
    COMPANY_NAME "YourName"
    PLUGIN_MANUFACTURER_CODE Juce
    PLUGIN_CODE Dem0
    FORMATS AU VST3 Standalone
    PRODUCT_NAME "Audio Plugin Example"
    COPY_PLUGIN_AFTER_BUILD TRUE
    NEEDS_WEB_BROWSER FALSE
    NEEDS_CURL FALSE)

target_sources(AudioPluginExample
    PRIVATE
        PluginEditor.cpp
        PluginProcessor.cpp)

target_compile_definitions(AudioPluginExample
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(AudioPluginExample
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
