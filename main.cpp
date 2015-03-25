#include "GLContexManager.h"
GLFWwindow* window;

//const static int g_DisplayMode = (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
static void error_callback(int error, const char* description)
{
	    fputs(description, stderr);
}
void InitModel()
{
	printf("hheee\n");
	StaticModel* model=(StaticModel*)RenderObjFactory::Instance()->CreateRenderObj(eRenderStatic);	
	model->LoadModel("square");	
	model->MoveModel(0.0,0.0,0.0);
	//StaticModel* model1=(StaticModel*)RenderObjFactory::Instance()->CreateRenderObj(0);	
	//model1->LoadModel("square");	
	//model1->MoveModel(0.1,0.0,0.0);
	RenderManager::Instance()->AddRenderObj(model);	
	//RenderManager::Instance()->AddRenderObj(model1);
	glm::vec3 position(0.0,0.0,5.0);
	glm::vec3 target(0.0,0.0,0.0);
	glm::vec3 up(0.0,1.0,0.0);
	RenderManager::Instance()->AddOneCamera(position,target,up);
	RenderManager::Instance()->SetCurCamera(0);
}
void RenderFunction()
{
    glViewport(0, 0, 512,512 ); // Set the viewport size to fill the window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // Clear required buffers
	//printf("hehe \n");
	//RenderALL();
	RenderManager::Instance()->DrawALL();

	
}
int main( void )
{   
	glfwSetErrorCallback(error_callback);
	window =GLContexManager::InitGLFWContex(4,0);	
	if(window == NULL)
	{
		return 0;
	}
	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	InitModel();
	bool needRender=false;	
	do{
		// Draw nothing, see you in tutorial 2 !
		{
			static double lastTime = glfwGetTime();
			double currentTime = glfwGetTime();
			float deltaTime = float(currentTime - lastTime);
			//printf("deltatime is %f\n",deltaTime);
			if(deltaTime > 1.0/60)
			{
			//	printf("deltatime is %f\n",deltaTime);
				needRender = true;
				lastTime = currentTime;
			}
		}
		if(needRender)
		{
			RenderFunction();
		}
		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

