#include "Life.hpp"

#include "Grid.hpp"
#include "CameraController.hpp"

void Life::start()
{
    setWidth(1000);
    setHeight(800);
    setTitle("Life");

    Scene scene;
    setActiveScene(scene);

    auto grid = activeScene->createEntity("Grid");
    std::shared_ptr<Grid> gridPtr = std::make_shared<Grid>(grid, activeScene);
    grid.addComponent<Script>(gridPtr);

    auto camera = activeScene->createEntity("Camera");
    std::shared_ptr<CameraController> cameraPtr = std::make_shared<CameraController>(camera, activeScene);
    camera.addComponent<Script>(cameraPtr);

    camera.addComponent<Transform>();
    camera.addComponent<Camera>();

    camera.getComponent<Camera>().isPrimary = true;

}

void Life::loadAssets()
{

    std::string title = "GridTexture";
    AssetManager::loadTexture2D(title, "../assets/2DTextures/grid.png");

    title = "TileTexture";
    AssetManager::loadTexture2D(title, "../assets/2DTextures/tile.png");
}

int main() 
{
    Life life;
    Application engine(life);
    engine.start();
    return 0;
}