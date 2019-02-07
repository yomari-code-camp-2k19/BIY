#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <stdio.h>

#include "glad/glad.h"
#include "glad/glDebug.h"

#include "GLFW/glfw3.h"
#include "resourceManager.h"
#include "renderer2d.h"

#include "Application.h"

static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char**)
{
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
		return 1;

	const char* glsl_version = "#version 330";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);


	GLFWwindow* window = glfwCreateWindow(1280, 720, "BIY-PC (Build it Yourself - PC)", NULL, NULL);
	if (window == NULL)
		return 1;

	glfwMaximizeWindow(window);

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	bool err = gladLoadGL() == 0;
	if (err)
	{
		fprintf(stderr, "Failed to initialize OpenGL loader!\n");
		return 1;
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImGui::StyleColorsLight();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);

	Application app;
	app.Init();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		app.Update();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		app.ImGUIFrame();

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		//glfwMakeContextCurrent(window);
		glfwGetFramebufferSize(window, &display_w, &display_h);
		a3GL(glViewport(0, 0, display_w, display_h));
		auto clear_color = a3::color::NotQuiteBlack;
		a3GL(glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f));
		a3GL(glClear(GL_COLOR_BUFFER_BIT));
		
		app.Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		//glfwMakeContextCurrent(window);
		glfwSwapBuffers(window);
	}

	//ImGui_ImplOpenGL3_Shutdown();
	//ImGui_ImplGlfw_Shutdown();
	//ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
