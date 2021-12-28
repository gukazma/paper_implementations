/*
 * @Author: ImGili
 * @Description: 
 */
#include<OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include<vector>

// Macros for extracting buffers from OpenMesh
#define VERTEX_DATA(mesh) (float*) &(mesh->point(*mesh->vertices_begin()))
#define NORMAL_DATA(mesh) (float*) &(mesh->normal(*mesh->vertices_begin()))
#define TEXTURE_DATA(mesh) (float*) &(mesh->texcoord2D(*mesh->vertices_begin()))

typedef OpenMesh::TriMesh_ArrayKernelT<> _Mesh;

class Mesh : public _Mesh {
private:
	std::vector<unsigned int> _ibuff;

public:
	// pointers to buffers
	float* vbuff();
	float* nbuff();
	float* tbuff();
	unsigned int* ibuff();

	// buffer sizes
	unsigned int vbuffLen();
	unsigned int nbuffLen();
	unsigned int tbuffLen();
	unsigned int ibuffLen();

	// set index buffer
	void useIBuff(std::vector<unsigned int>& _ibuff);
};