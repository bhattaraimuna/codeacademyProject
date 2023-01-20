#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race{
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
};

struct RaceCar{
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};

// Print functions section
void printIntro()
{
  printf("Welcome to our main event digital race fans! So, please put ease to your hearts as we are about to begin.\n\n"); 
}

void printCountDown()
{
  printf("Racers Ready! In...\n");
  printf("5\n4\n3\n2\n1\n");
  printf("Go!!!\n\n");
}

void printFirstPlaceAfterLap(struct Race race){
  printf("After lap number %d\n", race.currentLap);
  printf("First Place is: %s in the %s car\n",race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race)
{
  printf("Let's all congratulate %s in the %s car for an amazing performance.\n",race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}


// Logic functions section
int calculateTimeToCompleteLap()
{
  int speed = (rand() % 3 + 1);
  int acceleration = (rand() % 3 + 1);
  int nerves = (rand() % 3 + 1);
  return speed + acceleration + nerves;
}

int updateRaceCar(struct RaceCar* raceCar)
{
  int time = calculateTimeToCompleteLap();
  raceCar->totalLapTime += time ;
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2, struct RaceCar* raceCar3)
{
  
  if (raceCar1->totalLapTime > raceCar2->totalLapTime && raceCar1->totalLapTime > raceCar3->totalLapTime)
  {
    race->firstPlaceDriverName = raceCar1->driverName;
    race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
  }

  if (raceCar2->totalLapTime > raceCar3->totalLapTime && raceCar2->totalLapTime > raceCar1->totalLapTime)
  {
    race->firstPlaceDriverName = raceCar2->driverName;
    race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
  }

  else
  {
    race->firstPlaceDriverName = raceCar3->driverName;
    race->firstPlaceRaceCarColor = raceCar3->raceCarColor;
  }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2, struct RaceCar* raceCar3)
{
  struct Race race= {5,1," "," "};

  for (int i = 0; i< race.numberOfLaps; i++)
  {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateRaceCar(raceCar3);
    updateFirstPlace(&race, raceCar1, raceCar2, raceCar3);
    printFirstPlaceAfterLap(race);
    race.currentLap += 1;
  }

  printCongratulation(race);

}

int main() {

  struct RaceCar raceCar1 = {"Micky","Red", 0};
  struct RaceCar raceCar2 = {"Whoopie","Yellow", 0};
  struct RaceCar raceCar3 = {"Sandy","Blue", 0};
	srand(time(0));
  printIntro();
  printCountDown();
  startRace(&raceCar1, &raceCar2, &raceCar3);
  
};
