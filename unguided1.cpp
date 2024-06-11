#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int jumlahSimpul_2311102039;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jumlahSimpul_2311102039;
    
    vector<string> simpul(jumlahSimpul_2311102039);
    cout << "Silakan masukan nama simpul" << endl;
    for (int i = 0; i < jumlahSimpul_2311102039; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> simpul[i];
    }

    vector<vector<int>> bobot(jumlahSimpul_2311102039, vector<int>(jumlahSimpul_2311102039, 0));
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < jumlahSimpul_2311102039; i++) {
        for (int j = 0; j < jumlahSimpul_2311102039; j++) {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    cout << setw(15) << " ";
    for (int i = 0; i < jumlahSimpul_2311102039; i++) {
        cout << setw(15) << simpul[i];
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul_2311102039; i++) {
        cout << setw(15) << simpul[i];
        for (int j = 0; j < jumlahSimpul_2311102039; j++) {
            cout << setw(15) << bobot[i][j];
        }
        cout << endl;
    }

    return 0;
}
