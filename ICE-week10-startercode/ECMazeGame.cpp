// implement maze game

// Room
class Room
{
public:
  int GetPrize() const ...
};

// Room with a bomb
class RoomWithBomb ...
{
public:
  ...
};

// Enchanted room 
class EnchantedRoom ...
{
public:
  ...
};

// maze game
class MazeGame
{
public:
  MazeGame() {}
  ~MazeGame() ...
  
  // create a maze with two rooms and that is it!
  void CreateMaze()
  {
  ...
  }
  // get the total prize amount for the rooms
  int GetTotPrize() const
  {
 ...
  }
  
  Room* MakeRoom() ...
  
private:
  ...
};

// bombed maze
class BombedMazeGame ...
{
public:
...
};

// enchanted maze
class EnchantedMazeGame ...
{
public:
...
};
