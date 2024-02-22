#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

GLFWwindow *window;
VkInstance vkInstance;

uint32_t glfwExtensionCount = 0;
const char** glfwExtensions;

/* Private function */

void run();
void InitWindow();
void InitVulkan();
void MainLoop();
void Cleanup();
void CreateInstance();


int main()
{
    InitWindow();
    CreateInstance();
    MainLoop();
    Cleanup();
}

void run()
{
}

void InitWindow()
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(WIDTH, HEIGHT, "Project Rift\0", NULL, NULL);
}

void InitVulkan()
{
    CreateInstance();
}

void MainLoop()
{
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
}

void Cleanup()
{
    vkDestroyInstance(vkInstance, NULL);

    glfwDestroyWindow(window);

    glfwTerminate();
}

void CreateInstance()
{
    VkApplicationInfo appInfo = {
        
    .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
    .pNext = NULL,
    .pApplicationName = "Project_Rift",
    .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
    .pEngineName = "No Engine",
    .engineVersion = VK_MAKE_VERSION(1, 0, 0),
    .apiVersion = VK_API_VERSION_1_0,

    };

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    
    VkInstanceCreateInfo createInfo = {

    .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
    .pNext = NULL,
    .pApplicationInfo = &appInfo,
    .enabledLayerCount = 0,
    .ppEnabledLayerNames = NULL,
    .enabledExtensionCount = glfwExtensionCount,
    .ppEnabledExtensionNames = glfwExtensions,

    };

    VkResult result = vkCreateInstance(&createInfo, NULL, &vkInstance);
    
    if(result != VK_SUCCESS)
    {
        printf("Impossible de crée une instance Vulkan: \n");
        exit(EXIT_FAILURE);
    }
    
}


