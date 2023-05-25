#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void remove_directory(const fs::path &path)
{
    if (fs::exists(path))
    {
        if (fs::is_directory(path))
        {
            for (auto &entry : fs::directory_iterator(path))
            {
                remove_directory(entry.path());
            }
        }

        std::error_code ec;
        fs::remove(path, ec);

        if (ec)
        {
            std::cerr << "Error removing file/directory: " << ec.message() << '\n';
        }
    }
}
int main(int argc, char const *argv[])
{
    std::cout << argv[1];
    remove_directory(argv[1]);
    return 0;
}
