cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

message(VERBOSE "Executing patch step for vorbis")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "/Users/loicconstantineau/Desktop/VSCode/C++/PremierProjetSFML/build/_deps/vorbis-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[/usr/local/bin/cmake]====] [====[-DVORBIS_DIR=/Users/loicconstantineau/Desktop/VSCode/C++/PremierProjetSFML/build/_deps/vorbis-src]====] [====[-P]====] [====[/Users/loicconstantineau/Desktop/VSCode/C++/PremierProjetSFML/thirdParty/SFML/tools/vorbis/PatchVorbis.cmake]====]
)

endblock()
