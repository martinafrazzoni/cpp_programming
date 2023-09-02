// definisco le dimensioni dell'array
const int dim_a = 6; 
double a [dim_a]; 

// devo creare un nuovo file. 
ofstream file_reali; 
file_reali.open("dati.txt"); 

// controllo che il file si possa aprire 
if (!file_reali)
	cout << "L'apertura è fallita!\n"; 
// adesso devo scorrere l'array, chiedere all'utente di inserire i valori, e ogni valore lo devo scrivere dentro il file. 

cout << "Inserisci i valori per inizializzare l'array: \n"; 
for (int i = 0; i < dim_a; i++){
	cin>>a[i]; 
	file_reali<<a[i]
}

// adesso devo chiudere il file. 
file_reali.close(); 

// riapro il file, dandogli un altro nome
ifstream reali; 
reali.open("dati.txt"); 

// controllo che il file si possa aprire
if (!reali)
	cout << "L'apertura del file è fallita!" << endl; 
else 
cout << "Ecco il contenuto del file: \n"; 
for (int i = 0; i < dim_a; i++){
	while (reali >> a[i])
		cout << a[i] << endl; 

double n; // ho definito un'altra variabile e lì dentro ci metto n. 
        while (reali>>n){
            cout << n; 
        }
        cout << endl; 


for (double i = 0; i < dim_a; i++){
            reali>> a[i]; 
            cout << a[i] << " "; 
        }
