void esegui_turno (partita_info&p){
    int conta_combat_1 = 0; 
    int conta_combat_2 = 0; 
    if(p.conta_turni_1 == 0 || p.conta_turni_2 == 0){
        for (int i = 0; i < p.n; i++){
            if (p.giocatore_1[i] == '*'){
                conta_combat_1++; 
            }
        }

        for (int i = 0; i < p.n; i++){
            if (p.giocatore_2[i] == '*'){
                conta_combat_2++; 
            }
        }
        if (conta_combat_2 > conta_combat_1) {
            cout << "Ha vinto il giocatore 2!\n";
        } else if (conta_combat_1 > conta_combat_2) {
            cout << "Ha vinto il giocatore 1!\n";
        } else {
            cout << "La partita è finita in pareggio!\n";
        }
    }
    else if(p.turno == 1){
        cout << "Sta giocando il giocatore 1: \n"; 
        int pos; 
        do{
            cout << "Inserisci posizione del giocatore da eliminare\n";
            cin>>pos; 
        }
        while(pos < 0 || pos > p.n); 
        elimina_combattente(1, pos, p); // 1 è la fila. 
        // controllo se il turno dell'ultimo giocatore non è l'ultimo.
        if(p.conta_turni_1 > 0){
            p.conta_turni_1--; 
            p.turno = 2; 
        }
    }
	    else{
		// altrimentii è il turno del giocatore 2. 
        cout << "Sta giocando il giocatore 2: \n"; 
	    int pos; 
	    do{
		    cout << "Inserisci posizione del giocatore da eliminare\n"; 
		    cin>>pos; 
	    }
	    while(pos < 0 || pos > p.n); 
	    elimina_combattente(0, pos, p); 
	    // controllo se il turno dell'ultimo giocatore non è l'ultimo.
	    if(p.conta_turni_2>0){
		    p.conta_turni_2--; 
		    p.turno = 1;  
	    }
    }
}   
