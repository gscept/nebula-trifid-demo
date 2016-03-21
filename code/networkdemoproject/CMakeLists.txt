#-------------------------------------------------------------------------------
# netdemo
#-------------------------------------------------------------------------------

FILE(GLOB SRC "gamestates/*.cc")
FILE(GLOB HEAD "gamestates/*.h")
LIST(APPEND SRCSGAMESTATES ${SRC} ${HEAD})
SOURCE_GROUP("netdemoproject\\gamestates" FILES ${SRCSGAMESTATES})

FILE(GLOB SRC "*.cc")
FILE(GLOB HEAD "*.h")
LIST(APPEND SRCSBASE ${SRC} ${HEAD})
SOURCE_GROUP("netdemoproject" FILES ${SRCSBASE})

set(PCH_files	
    ../stdneb.cc
)
SOURCE_GROUP("Precompiled" FILES ${PCH_files})

LIST(APPEND ALLSRCS ${SRCSBASE} ${SRCSGAMESTATES} ${PCH_files})

ADD_EXECUTABLE(netdemoproject ${ALLSRCS})
SET_TARGET_PROPERTIES(netdemoproject PROPERTIES FOLDER "Demos")

N_SET_COMPILER_DEFAULTS()
N_SET_EXE_LINKER_DEFAULTS(netdemoproject)
N_SET_EXE_SUBSYSTEM(netdemoproject Windows)
IF(N_USE_PRECOMPILED_HEADERS)
	N_SET_PCH(netdemoproject  stdneb.h stdneb.cc ../)
ENDIF()
ADD_DEPENDENCIES(netdemoproject
	application_features ui multiplayer
	)
TARGET_LINK_LIBRARIES(netdemoproject 
        application_features ui multiplayer
)


