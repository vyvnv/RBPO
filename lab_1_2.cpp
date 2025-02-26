#include <iostream>
#include <string>

using namespace std;
class Image {
private:
   
    string imageSize;
    string format;
    string url = "";
public: 
    string imageName;
    Image(string n = "image.png") : imageName(n) {}
};

class Account {
private:
    string username;
    int id;
};

class FileManager {
public:
    static void Save(const Image& image) {
        cout << "Saving an image in the filesystem" << endl;
    }

    static int DeleteDuplicates() {
        cout << "Deleting duplicates..." << endl;
        return 3; // якобы удалили 3 дубликата
    }
};

class ImageProcessor {
public:
    static Image Resize(const Image& image, int height, int width) {
        cout << "Size changed to " << height  << " X " << width << endl;
        return Image(image.imageName + "_upd");
    }

    static Image InvertColors(const Image& image) {
        cout << "Inverting img colors " << image.imageName << "." << endl;
        return Image(image.imageName + "_inv");
    }
};

class AccountManager {
public:
    static void SetImageAsAccountPicture(const Image& image, const Account& account) {
        cout << "Set an image" << image.imageName << " as an avatar";
    }
};

class ImageDownloader {
public:
    static unsigned char* Download(const std::string& imageUrl) {
        cout << "Downloaded an image from " << imageUrl;
        unsigned char * tmp_arr = new unsigned char[30];
        return tmp_arr;
    }
};

int main() {
    Image img;
    Account acc;

    FileManager::Save(img);
    Image resized = ImageProcessor::Resize(img, 100, 100);
    AccountManager::SetImageAsAccountPicture(resized, acc);

    return 0;
}

