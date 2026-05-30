cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

message(VERBOSE "Executing patch step for freetype")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "/Users/loicconstantineau/Desktop/VSCode/C++/PremierProjetSFML/build/_deps/freetype-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[/usr/local/bin/cmake]====] [====[-DFREETYPE_DIR=/Users/loicconstantineau/Desktop/VSCode/C++/PremierProjetSFML/build/_deps/freetype-src]====] [====[-P]====] [====[/Users/loicconstantineau/Desktop/VSCode/C++/PremierProjetSFML/thirdParty/SFML/tools/freetype/PatchFreetype.cmake]====]
)

endblock()
