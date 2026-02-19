#include <iostream>
using namespace std;

class SettingManager {
	private:
		string theme = "dark";
		int volume  = 50;
		string language = "ARM";
		static int count;

		SettingManager() {
			cout << "constructor\n";
			count++;
		}
		SettingManager(const SettingManager& manager) = delete;
		SettingManager operator=(const SettingManager& that) = delete;
	public:


		static SettingManager* getInstance() {
			return (!count ? new SettingManager() : nullptr);
		}

		void changeTheme(const string& choice) {
			if (choice == "dark" || choice == "light") {
				theme = choice;
			}
		}

		void changeVolume(int choice) {
			if (choice >= 0 && choice <= 100) {
				volume = choice;
			}
		}

		void changeLang(string choice) {
			if (choice == "ARM" || choice == "ENG" || choice == "FR") {
				language = choice;
			}
		}

		void showSettings() {
			cout << "Volume: " << volume << endl;
			cout << "Language: " << language<< endl;
			cout << "Theme: " << theme<< endl;
		}

		~SettingManager() {
			count--;
		}


};

int SettingManager::count = 0;

int main(){

	SettingManager* manager = SettingManager::getInstance();
	cout << manager<<endl;
	
	manager->showSettings();
	manager->changeTheme("light");
	manager->changeVolume(69);
	manager->changeLang("FR");
	manager->showSettings();
	
	delete manager;
}

