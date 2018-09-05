class GameState {
    public:
        GameState(
            const std::unique_ptr<SDL2pp::Renderer> & renderer,
            const std::unique_ptr<AssetsManager> & assetsManager,
        );
        std::shared_ptr<Client> mClient;
        const std::unique_ptr<SDL2pp::Renderer> & renderer;
        const std::unique_ptr<AssetsManager> & assetsManager;
        void HandleInput();
        void Update();
        void Shoot();
        
    private:
        std::map<std::string, std::shared_ptr<Client>> clients;
        std::map<std::string, std::shared_ptr<Bullet>> bullets;
}