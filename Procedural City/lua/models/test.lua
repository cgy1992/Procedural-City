createNode()
addVertex(-0.5, -0.5, 0)
addVertex(-0.5, 0.5, 0)
addVertex(0.5, 0.5, 0)
addVertex(0.5, -0.5, 0)
addNormal(0, 0, 1)
addNormal(0, 0, 1)
addNormal(0, 0, 1)
addNormal(0, 0, 1)
addUV(0, 0)
addUV(0, 1)
addUV(1, 1)
addUV(1, 0)
addTriangle(0, 3, 2)
addTriangle(2, 1, 0)
addTriangle(0, 1, 2)
addTriangle(2, 3, 0)
setPixelShader("road/broken_white")

createNode()
addVertex(-1, -1, 0)
addVertex(-1, 1, 0)
addVertex(1, 1, 0)
addVertex(1, -1, 0)
addNormal(0, 0, 1)
addNormal(0, 0, 1)
addNormal(0, 0, 1)
addNormal(0, 0, 1)
addUV(0, 0)
addUV(0, 1)
addUV(1, 1)
addUV(1, 0)
addTriangle(0, 3, 2)
addTriangle(2, 1, 0)
addTriangle(0, 1, 2)
addTriangle(2, 3, 0)
setPosition(0, 0, 1)
setPixelShader("bricks")