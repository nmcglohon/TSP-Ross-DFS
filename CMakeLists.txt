INCLUDE_DIRECTORIES(${ROSS_SOURCE_DIR} ${ROSS_BINARY_DIR})
## Must include binary dir for config.h

## If you will be using the RIO library add this
#INCLUDE_DIRECTORIES(${RIO_SOURCE_DIR} ${RIO_BINARY_DIR})

## Model Version
LIST(APPEND CMAKE_MODULE_PATH "${ROSS_SOURCE_DIR}/cmake/")
INCLUDE(GetGitRevisionDescription)
GET_GIT_HEAD_REVISION(GIT_RESPEC_MODEL GIT_SHA1_MODEL)

## Build Configuration Header File
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/model_config.h.in ${CMAKE_CURRENT_BINARY_DIR}/model_config.h @ONLY)
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/model_config.h.in PROPERTIES GENERATED FALSE)
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_BINARY_DIR}/model_config.h PROPERTIES GENERATED TRUE)

# All source files for the model
SET(tspdfs_srcs
	tsp.h
	structs.h
	priority_queue.h
	priority_queue.c
	tsp_main.c
	tsp_driver.c
	tsp_map.c
	model_config.h
)

# Set the executable name here: tspdfs
# You will be executing the ./tsps binary
ADD_EXECUTABLE(tspdfs ${tspdfs_srcs})

TARGET_LINK_LIBRARIES(tspdfs ROSS m)
## Alternatively, use this command with RIO
#TARGET_LINK_LIBRARIES(model ROSS RIO m)
