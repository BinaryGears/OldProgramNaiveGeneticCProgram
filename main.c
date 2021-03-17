#include <stdio.h>
#include <time.h>


int main()
{
	/*
	char test[30];
	int genNums = 1;
	int times = 0;
	*/

	/* srand is needed to keep random numbers random... without this line the random numbers will be the same all the time*/
	srand((unsigned)time(0));

	/*All of the variables that are needed so far*/
	int AllDead = 0;
	int addMore = 0;
	int TotalAlive = 0;
	int done = 0;
	int SomeoneDied = 0;
	int AllTimeCounter = 0;
	int Breaker;
	int MakeSureAllHaveBaby = 0;

	/*The Actor struct*/
	struct Actors
	{
		int id;
		int lifeChance[7];
		int lifeChanceScore;
		int PrintChar[6];
		int Checker;
		int Alive;
		int PassOnGenes[7];
		int PassCrossover;
		int JustBorn;
		int AlreadyHadBaby;
	};

	/*Array of structs*/
	struct Actors Actor[120];

	/*For loop to make Actors. All Actors have a total life score based on a total of the random life chance array values*/
	for (int i = 0; i < 10; i++)
	{
		Actor[i].lifeChance[0] = rand() % 2;
		Actor[i].lifeChance[1] = rand() % 2;
		Actor[i].lifeChance[2] = rand() % 2;
		Actor[i].lifeChance[3] = rand() % 2;
		Actor[i].lifeChance[4] = rand() % 2;
		Actor[i].lifeChance[5] = rand() % 2;
		Actor[i].lifeChance[6] = rand() % 2;

		
		AllDead++;
		TotalAlive++;
		AllTimeCounter++;

		Actor[i].id = AllTimeCounter;

		Actor[i].Alive = 1;

		Actor[i].AlreadyHadBaby = 0;
		Actor[i].JustBorn = 0;

		Actor[i].lifeChanceScore = Actor[i].lifeChance[0] + Actor[i].lifeChance[1] +
			Actor[i].lifeChance[2] + Actor[i].lifeChance[3] + Actor[i].lifeChance[4] + Actor[i].lifeChance[5];

	}
	
	/*This for loop sets all Actors not made in the for loop above as not alive*/
	for (int i = TotalAlive; i < 120; i++)
	{
		Actor[i].Alive = 0;
	}

	/*Main While loop has a goto label attached for testing purpose only*/
	MAINWHILE:while (TotalAlive > 0)
	{
		printf("\n[Total Alive: %d]\n", TotalAlive);
		addMore++;

		/*The birth logic starts here*/
		if (addMore > 4 && TotalAlive < 120)
		{
			addMore = 0;
			MakeSureAllHaveBaby = 0;

			/*This should reset the variables to determine who should have a baby and who already has*/
			for (int m = 0; m < 120; m++)
			{
				Actor[m].AlreadyHadBaby = 0;
				Actor[m].JustBorn = 0;
			} 
			
			/*This while loop was just added to try to fix the issue but has not worked*/
			//while (MakeSureAllHaveBaby < 120)
			//{
				/*This for loop was added to try to fix the issue as well*/
				//for (int AllBaby = 0; AllBaby < 120; AllBaby++)
				//{
					//MakeSureAllHaveBaby++;

					/*In this for loop variable i was set equal to variable AllBaby from for loop above to try to fix the issue as well. i was set to 0 before
					I want to loop through all the Actors still alive and make sure they all have a baby only once and only when there is another Actor 
					alive to have a baby with who has not already had a baby*/
					TESTGOTO:for (int i = 0; i < 120; i++)
					{
						//find Alive Actor
						if (Actor[i].Alive == 1 && TotalAlive != 120 && Actor[i].AlreadyHadBaby == 0 && Actor[i].JustBorn == 0)
						{
							MakeSureAllHaveBaby++;

							if (MakeSureAllHaveBaby > 120)
							{
								break;
							}

							for (int j = 0; j < 120; j++)
							{
								//find second Alive Actor
								if (Actor[j].Alive == 1 && Actor[j].id != Actor[i].id && Actor[j].AlreadyHadBaby == 0 && Actor[j].JustBorn == 0)
								{
									//printf("Getting past j alive");

									//find empty index to insert new Actor
									for (int k = j; k < 120; k++)
									{
										//printf("Getting past k forloop");

										if (Actor[k].Alive == 0 && Actor[i].AlreadyHadBaby == 0 && Actor[j].AlreadyHadBaby == 0)
										{
											//printf("Getting past k alive");
											printf("\nActor%d and Actor%d having a baby\n", Actor[i].id, Actor[j].id);
											Actor[i].AlreadyHadBaby = 1;
											Actor[j].AlreadyHadBaby = 1;
											int tempCrossPoint = rand() % 2;
											Actor[i].PassCrossover = rand() % 2;
											Actor[j].PassCrossover = rand() % 2;

											//All the code below is used to determine the genes passing over to baby

											if (Actor[i].PassCrossover == 0 && Actor[j].PassCrossover == 0)
											{
												switch (tempCrossPoint)
												{
												case 0:
													Actor[k].lifeChance[0] = Actor[i].lifeChance[0];
													Actor[k].lifeChance[1] = Actor[i].lifeChance[1];
													Actor[k].lifeChance[2] = Actor[i].lifeChance[2];
													Actor[k].lifeChance[3] = Actor[j].lifeChance[0];
													Actor[k].lifeChance[4] = Actor[j].lifeChance[1];
													Actor[k].lifeChance[5] = Actor[j].lifeChance[2];
													break;
												case 1:
													Actor[k].lifeChance[0] = Actor[j].lifeChance[0];
													Actor[k].lifeChance[1] = Actor[j].lifeChance[1];
													Actor[k].lifeChance[2] = Actor[j].lifeChance[2];
													Actor[k].lifeChance[3] = Actor[i].lifeChance[0];
													Actor[k].lifeChance[4] = Actor[i].lifeChance[1];
													Actor[k].lifeChance[5] = Actor[i].lifeChance[2];
													break;
												default:
													printf("Problem In Switch?");
													break;
												}
											}

											else if (Actor[i].PassCrossover == 1 && Actor[j].PassCrossover == 0)
											{
												switch (tempCrossPoint)
												{
												case 0:
													Actor[k].lifeChance[0] = Actor[i].lifeChance[3];
													Actor[k].lifeChance[1] = Actor[i].lifeChance[4];
													Actor[k].lifeChance[2] = Actor[i].lifeChance[5];
													Actor[k].lifeChance[3] = Actor[j].lifeChance[0];
													Actor[k].lifeChance[4] = Actor[j].lifeChance[1];
													Actor[k].lifeChance[5] = Actor[j].lifeChance[2];
													break;
												case 1:
													Actor[k].lifeChance[0] = Actor[j].lifeChance[0];
													Actor[k].lifeChance[1] = Actor[j].lifeChance[1];
													Actor[k].lifeChance[2] = Actor[j].lifeChance[2];
													Actor[k].lifeChance[3] = Actor[i].lifeChance[3];
													Actor[k].lifeChance[4] = Actor[i].lifeChance[4];
													Actor[k].lifeChance[5] = Actor[i].lifeChance[5];
													break;
												default:
													printf("Problem In Switch?");
													break;
												}
											}

											else if (Actor[i].PassCrossover == 0 && Actor[j].PassCrossover == 1)
											{
												switch (tempCrossPoint)
												{
												case 0:
													Actor[k].lifeChance[0] = Actor[i].lifeChance[0];
													Actor[k].lifeChance[1] = Actor[i].lifeChance[1];
													Actor[k].lifeChance[2] = Actor[i].lifeChance[2];
													Actor[k].lifeChance[3] = Actor[j].lifeChance[3];
													Actor[k].lifeChance[4] = Actor[j].lifeChance[4];
													Actor[k].lifeChance[5] = Actor[j].lifeChance[5];
													break;
												case 1:
													Actor[k].lifeChance[0] = Actor[j].lifeChance[3];
													Actor[k].lifeChance[1] = Actor[j].lifeChance[4];
													Actor[k].lifeChance[2] = Actor[j].lifeChance[5];
													Actor[k].lifeChance[3] = Actor[i].lifeChance[0];
													Actor[k].lifeChance[4] = Actor[i].lifeChance[1];
													Actor[k].lifeChance[5] = Actor[i].lifeChance[2];
													break;
												default:
													printf("Problem In Switch?");
													break;
												}
											}

											else
											{
												switch (tempCrossPoint)
												{
												case 0:
													Actor[k].lifeChance[0] = Actor[i].lifeChance[3];
													Actor[k].lifeChance[1] = Actor[i].lifeChance[4];
													Actor[k].lifeChance[2] = Actor[i].lifeChance[5];
													Actor[k].lifeChance[3] = Actor[j].lifeChance[3];
													Actor[k].lifeChance[4] = Actor[j].lifeChance[4];
													Actor[k].lifeChance[5] = Actor[j].lifeChance[5];
													break;
												case 1:
													Actor[k].lifeChance[0] = Actor[j].lifeChance[3];
													Actor[k].lifeChance[1] = Actor[j].lifeChance[4];
													Actor[k].lifeChance[2] = Actor[j].lifeChance[5];
													Actor[k].lifeChance[3] = Actor[i].lifeChance[3];
													Actor[k].lifeChance[4] = Actor[i].lifeChance[4];
													Actor[k].lifeChance[5] = Actor[i].lifeChance[5];
													break;
												default:
													printf("Problem in swtich?");
													break;
												}
											}

											//Code to make baby
											AllTimeCounter++;
											Actor[k].Alive = 1;
											Actor[k].id = AllTimeCounter;
											Actor[k].JustBorn = 1;

											Actor[k].lifeChanceScore = Actor[k].lifeChance[0] + Actor[k].lifeChance[1] + Actor[k].lifeChance[2] +
												Actor[k].lifeChance[3] + Actor[k].lifeChance[4] + Actor[k].lifeChance[5];

											TotalAlive++;
											AllDead++;

											printf("\nActor%d just born\n", Actor[k].id);

											goto TESTGOTO;
											//goto MAINWHILE;
										}
										/*
										else
										{
											break;
										}
										*/
									}
								}

								//else
								//{
									//break;
								//}
							}

						}
					//}
				//}
			}
		}

			/*This is the code that runs at the beginning of the main while loop*/
			for (int i = 0; i < 120; i++)
			{
				if (Actor[i].Alive == 1)
				{ 

				Actor[i].Checker = 0;


				if (Actor[i].lifeChanceScore < 4)
				{
					for (int j = 0; j < 6; j++)
					{
						Actor[i].PrintChar[j] = rand() % 11;

						if (Actor[i].PrintChar[j] < 8)
						{
							Actor[i].PrintChar[j] = 43;
							Actor[i].Checker = Actor[i].PrintChar[j] + Actor[i].Checker;
						}

						else
						{
							Actor[i].PrintChar[j] = 45;
							Actor[i].Checker = Actor[i].PrintChar[j] + Actor[i].Checker;
						}

						if (Actor[i].Checker == 90)
						{
							printf("\nActor%d is dead at index :%d      LifeChanceNumber%d", Actor[i].id, j, Actor[i].lifeChanceScore);
							Actor[i].Alive = 0;
							AllDead--;
							SomeoneDied++;
							break;
						}

						Actor[i].Checker = Actor[i].PrintChar[j];
					}
				}

				else
				{
					for (int j = 0; j < 6; j++)
					{
						Actor[i].PrintChar[j] = rand() % 11;

						if (Actor[i].PrintChar[j] < 10)
						{
							Actor[i].PrintChar[j] = 43;
							Actor[i].Checker = Actor[i].PrintChar[j] + Actor[i].Checker;
						}

						else
						{
							Actor[i].PrintChar[j] = 45;
							Actor[i].Checker = Actor[i].PrintChar[j] + Actor[i].Checker;
						}

						if (Actor[i].Checker == 90)
						{
							printf("\nActor%d is dead at index :%d      LifeChanceNumber%d", Actor[i].id, j, Actor[i].lifeChanceScore);
							Actor[i].Alive = 0;
							AllDead--;
							SomeoneDied++;

							break;
						}

						Actor[i].Checker = Actor[i].PrintChar[j];
					}
				}

				}
			}
			
			if (SomeoneDied != 0)
			{
				for (int k = 0; k < 119; k++)
				{
					if (Actor[k].Alive == 0 && Actor[k + 1].Alive == 1)
					{
						Actor[k] = Actor[k + 1];
						Actor[k + 1].Alive = 0;
					}
				}
			}

			TotalAlive = AllDead;
			getchar();
	}
	
	printf("\n\n**********All actors are dead!!!**********\n\n\n");
	return 0;
}
