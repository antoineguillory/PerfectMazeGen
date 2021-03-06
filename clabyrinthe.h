#pragma once
#include "ccase.h"
#include <vector>
#include <utility>
#include <fstream>
class CLabyrinthe
{
    private:
        std::vector <std::vector <CCase>>  m_Labyrinthe;
        unsigned m_X;
        unsigned m_Y;
        CCase m_Enter;
        CCase m_Exit;
        std::pair<std::pair<unsigned, unsigned>, unsigned short> m_CoordEnter;
        std::pair<std::pair<unsigned, unsigned>, unsigned short> m_CoordExit;
        bool solved;
    public:
        CLabyrinthe(const unsigned & y, const unsigned & x) noexcept;
        CLabyrinthe(const CLabyrinthe * lab) noexcept;
        ~CLabyrinthe();


        /*** METHODES ***/
        void Afficher();
        void AfficherPlusChemin();
        void Afficher(std::ofstream &bobstream);
        void AfficherPlusChemin(std::ofstream &bobstream);
        void AfficherDebug();
        void Solve();
        CLabyrinthe ReturnSolved();

        void IdChemin(const unsigned & info, const unsigned short & Direction, unsigned X, unsigned Y, CLabyrinthe* laby);
        void GenLaby() noexcept;
        std::pair<std::pair<unsigned, unsigned>, unsigned short> GetCoordEnter();
        std::pair<std::pair<unsigned, unsigned>,unsigned short> GetCoordExit();

        void SetLabyrinthe(std::vector<std::vector<CCase>> lab) const;
        void Solved(void);


        /*** GETTERS ***/
        CCase GetEnter(void);
        CCase GetExit(void);
        bool IsSolved(void);

        std::vector<std::vector<CCase>> GetLabyrinthe() const;

};
