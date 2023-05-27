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
            std::cerr << "Error removing file/directory: " << path << '\n';
        }
    }
}
int main(int argc, char const *argv[])
{
    remove_directory(argv[1]);
    return 0;
}
