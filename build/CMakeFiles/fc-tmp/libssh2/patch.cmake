cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

message(VERBOSE "Executing patch step for libssh2")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "/Users/loicconstantineau/Desktop/VSCode/C++/PremierProjetSFML/build/_deps/libssh2-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[/usr/local/bin/cmake]====] [====[-DLIBSSH2_DIR=/Users/loicconstantineau/Desktop/VSCode/C++/PremierProjetSFML/build/_deps/libssh2-src]====] [====[-DMODULES_DIR=/Users/loicconstantineau/Desktop/VSCode/C++/PremierProjetSFML/thirdParty/SFML/src/SFML/Network/../../../cmake/Modules]====] [====[-P]====] [====[/Users/loicconstantineau/Desktop/VSCode/C++/PremierProjetSFML/thirdParty/SFML/tools/libssh2/PatchLibssh2.cmake]====]
)

endblock()
