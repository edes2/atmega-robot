#ifndef STATES_H
#define STATES_H

// Contient tous les etats dans lesquels le robot peut etre.
enum Etats
{
    init,
    debutParcours,
    debutReprise,
    modeExecutionEnregistrement,
    toutDroit,
    modeSuivreMur,
    attente,
    modeSuivreLumiere,
    finParcours,
    finFinal,
    modeVirage
};

#endif