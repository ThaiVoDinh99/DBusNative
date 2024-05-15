file(REMOVE_RECURSE
  "main.qml"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/UI_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
