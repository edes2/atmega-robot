#include "interpreteurinstructions.h"

void InterpreteurInstructions::associerCode(){
    LED led1(&DDRA, &PORTA, 0, 1);
    LED led2(&DDRA, &PORTA, 2, 3);
    LED led3(&DDRA, &PORTA, 4, 5);
    LED led4(&DDRA, &PORTA, 6, 7);
    LED led5(&DDRB, &PORTB, 0, 1);
    LED led6(&DDRB, &PORTB, 4, 5);
    LED led7(&DDRB, &PORTB, 6, 7);
    LED tableauDeLed[7] = {led1, led2, led3, led4, led5, led6, led7};

    Driver robot;
    JoueurPiezo piece;
    Memoire24CXXX memoire;  // Mémoire externe    
    // variables
    uint16_t lectureAct = 0x0000;
    uint16_t longueur;
    uint8_t compteur = 0;
    
    uint16_t enregistrerPosition = 0x00;
    bool dansBoucle = false;

    double pourcentage;

    char buffer[50];

    // Vérification de la lecture (comme indiqué sur le site web)
    DEBUG_PRINT(("Debut des Tests...\n"));
    led1.Rouge();
    _delay_ms(500);
    led1.Off(); 
    led1.Rouge();
    _delay_ms(500);
    led1.Off();
    DEBUG_PRINT(("Debut des protocoles...\n"));

    while(commandes__ != DBT){
        memoire.lecture(lectureAct, &commandes_);
        _delay_ms(5);
        DEBUG_PRINT(("Iteration de la boucle \n"));
        lectureAct += 2;
    }

    DEBUG_PRINT(("Debut de la lecture d'instruction \n"));
    // Nombre d'octets à lire.
    while(commandes_ != FIN){
        memoire.lecture(lectureAct, &commandes_);
        _delay_ms(5);
        lectureAct += 1;

        memoire.lecture(lectureAct, &operande_);
        _delay_ms(5);
        lectureAct += 1;

        
        itoa(commandes_, buffer, 16);
        DEBUG_PRINT(("Commande: \n"));
        DEBUG_PRINT((buffer));

        itoa(operande_, buffer, 16);
        DEBUG_PRINT(("Operande: \n"));
        DEBUG_PRINT((buffer));

        switch (commandes_)
        {
            case ATT:{
                DEBUG_PRINT(("\n ATT \n"));
                uint16_t dureeDelai = 25 * operande_;
                for (uint16_t i = 0; i<dureeDelai;i++)
                {
                    _delay_ms(1);
                }
                break;
            }
            case DAL:{
                DEBUG_PRINT(("\n DAL \n"));
                for(int i = 0; i < 7; i++){
                    
                    if (1 & (operande_ >> (i+1)) == 1){
                        tableauDeLed[i].Rouge();
                    }
                    
                }
                break;
            }
            case DET:{
                DEBUG_PRINT(("\n DET \n"));
                for(int i = 0; i < 7; i++){ 
                    if (1 & (operande_ >> (i+1)) != 1){
                        tableauDeLed[i].Off();
                    }
                }
                break;
            }
            case SGO:{
                DEBUG_PRINT("\n SGO \n");
                if (operande_ >= 45 && operande_ <= 81){
                    piece.jouerNote(operande_);
                }
                break;
            }
            case SAR:{
                DEBUG_PRINT(("\n SAR \n"));
                piece.silence();
                break;
            }
            case MAR1:{
                DEBUG_PRINT(("\n MAR1 \n"));
                robot.stop(); 
                break;
            }
            case MAR2:{
                DEBUG_PRINT(("\n MAR2 \n"));
                robot.stop();
                break;
            }
            case MAV:{
                DEBUG_PRINT(("\n MAV \n"));
                pourcentage = (double)operande_/255;
                robot.avancer(pourcentage);
                break;
            }
            case MRE:{
                DEBUG_PRINT(("\n MRE \n"));
                pourcentage = (double)operande_/255;
                robot.reculer(pourcentage);
                break;
            }
            case TRD:{
                DEBUG_PRINT(("\n TRD \n"));
                robot.tournerADroite(0.53);
                _delay_ms(1000);
                robot.stop();
                break;
            }
            case TRG:{
                DEBUG_PRINT(("\n TRG \n"));
                robot.tournerAGauche(0.53);
                _delay_ms(1000);
                robot.stop();
                break;
            }
            case DBC:{
                DEBUG_PRINT(("\n DBC \n"));
                dansBoucle = true;
                DEBUG_PRINT("Debut boucle \n");
                enregistrerPosition = lectureAct;
                compteur = operande_;
                break;
            }
            case FBC:{
                DEBUG_PRINT(("\n TRG \n"));
                DEBUG_PRINT("Fin boucle \n");
                if (compteur != 0){
                    compteur -= 1;
                    lectureAct = enregistrerPosition;
                }
                break;
            }
        }
    }


}