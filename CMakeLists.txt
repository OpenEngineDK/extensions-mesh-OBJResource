SET( EXTENSION_NAME "Extensions_OBJResource")

ADD_LIBRARY( ${EXTENSION_NAME}
  Resources/OBJResource.cpp
)

TARGET_LINK_LIBRARIES( ${EXTENSION_NAME}
  OpenEngine_Resources
  OpenEngine_Geometry
  OpenEngine_Logging
  OpenEngine_Scene
  OpenEngine_Utils
)
