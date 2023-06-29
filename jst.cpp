#include <iostream>
#include <cmath>

using namespace std;

int stepFunction(double sum) {
    return (sum >= 0) ? 1 : 0;
}

double summation(double input[], double weights[]) {
    double sum = weights[0] * input[0] + weights[1] * input[1] + weights[2] * input[2];
    cout << "Jumlah : " <<  sum << endl;
    return sum;
}

void train(double inputSeq[][3], double target[], double weights[], double learningRate, int epochs) {
    bool exitLoop = false;
    for (int epoch = 0; epoch < epochs && !exitLoop; epoch++) {
        double totalError = 0.0;
        cout << "Epoch ke : " << epoch + 1 << endl;
        for (int i = 0; i < 4  && !exitLoop; i++) {
            double input[] = { inputSeq[i][0], inputSeq[i][1], inputSeq[i][2] };
            cout << "input : " << input[0] << " " << input[1] << " " << input[2] << endl;
            double output = stepFunction(summation(input, weights));
            cout << "target : " << target[i] << endl;
            double error = target[i] - output;
            totalError += abs(error);
            cout << "output : " << output << endl;
            weights[0] += learningRate * error * input[0];
            cout << "w1 baru : " << weights[0] << endl;
            weights[1] += learningRate * error * input[1];
            cout << "w2 baru : " <<weights[1] << endl;
            weights[2] += learningRate * error * input[2];
            cout << "w3 baru : " <<weights [2] << endl;
            if (error < 0)
            {
                cout << "output tidak sesuai target maka error" << endl;
            } else {
                cout << "output sesuai target" << endl;
            }
            
            string choice;
            cout << "Apakah ingin dilanjutkan ? (yes/no)" << endl;
            cin >> choice;
            if (choice == "no")
            {
                exitLoop=true;
            }
            
        }
        cout <<" Total Error: " << totalError << endl;
    }
}

int main() {
    cout<<"========================================"<<endl;
	cout<<"              KELOMPOK 1 "<<endl;
	cout<<"========================================"<<endl;
	cout<<"           Anggota Kelompok :"<<endl;
	cout<<"1. Faiz Nur Budi            -  21081010113"<<endl;
	cout<<"2. Nasywa Andin Safitri     -  21081010265"<<endl;
	cout<<"3. Siti Nur Rohmatul Ummah  -  20081010200"<<endl;
    cout<<"4. M Wahyu Anugrahan        -  20081010318"<<endl;
	cout<<"========================================\n"<<endl;
	cout<<"========================================"<<endl;
	cout<<"  FINAL PROJECT KECERDASAN BUATAN B081  "<<endl;
	cout<<"              ALGORTIMA AND             "<<endl;
	cout<<"========================================\n"<<endl;
    double inputSeq[][3] = { {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1} };
    double target[] = {0, 0, 0, 1};

    double weights[] = {0.706, 0.533, 0.58};
    cout << "threshhold = 0" << endl;
    cout << "w1 awal : " << weights[0] << "\nw2 awal " << weights[1] << "\nw3 awal " << weights[2] << endl;    
    double learningRate = 0.1;
    int epochs = 10;

    train(inputSeq, target, weights, learningRate, epochs);

    cout << "Trained Weights: " << weights[0] << ", " << weights[1] << ", " << weights[2] << endl;

    cout << "Hasil Akhir : " << endl;
    for (int i = 0; i < 4; i++) {
        double input[] = { inputSeq[i][0], inputSeq[i][1], inputSeq[i][2] };
        double output = stepFunction(summation(input, weights));
        cout << "Input: " << inputSeq[i][0] << ", " << inputSeq[i][1] << ", " << inputSeq[i][2] << " Output: " << output << endl;
    }

    return 0;
}