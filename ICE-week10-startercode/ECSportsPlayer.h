#ifndef _EC_SPORTS_PLAYER_H
#define _EC_SPORTS_PLAYER_H

// ********************************************
// Sports Tournament
class ECTournament
{
public:
  ECTournament(int mon, int mr) : month(mon), minRank(mr) {}
  int GetMonth() const { return month; }
  int GetMinRank() const { return minRank; }

private:
  int month;
  int minRank;
};

// ********************************************
// Generic player
class ECSportsPlayer
{
public:
  virtual bool CanPlay(ECTournament &tr) const;

  // Your code
};

// ********************************************
// Ranked player
class ECSportsPlayerRanked : public ECSportsPlayer
{
public:
  ECSportsPlayerRanked(int r);

private:
  // your code
};


// ********************************************
// Wildcard player: qualify for any tournament 
class ECSportsPlayerWildcard 
{
public:
  ECSportsPlayerWildcard(ECSportsPlayer &playerOrig); 
};

// ********************************************
// Displined player: cannot attend any tournament during the period of probation
class ECSportsPlayerDisciplined 
{
public:
  ECSportsPlayerDisciplined(ECSportsPlayer &playerOrig, int mStart, int mEnd);

private:
};

// ********************************************
// Injured player: cannot attend any tournament during the period of injury(injury occurs at a single month) 
class ECSportsPlayerInjured 
{
public:
  ECSportsPlayerInjured(ECSportsPlayer &playerOrig, int m);

private:
};

#endif
