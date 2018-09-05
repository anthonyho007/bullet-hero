class Object {
    public:
        const std::string id;
        SDL2pp::Point position;
        SDL2pp::Point velocity;


    protected:
        const std::unique_ptr<SDL2pp::Renderer> & renderer;
        const std::unique_ptr<AssetsManager> & assetsManager;
        const std::string textureKey;

        virtual void Update() {}
}