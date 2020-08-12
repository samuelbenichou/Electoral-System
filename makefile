run: main.o DemocratLeaderPolitician.o DemocratPolitician.o DemocratSocialPolitician.o Democratic.o Leader.o Party.o PoliticalSys.o Politician.o Republican.o RepublicanLeaderPolitician.o RepublicanPolitician.o RepulicanSocialPolitician.o Social.o
    g++  main.o DemocratLeaderPolitician.o DemocratPolitician.o DemocratSocialPolitician.o Democratic.o Leader.o Party.o PoliticalSys.o Politician.o Republican.o RepublicanLeaderPolitician.o RepublicanPolitician.o RepulicanSocialPolitician.o Social.o -o Run

main.o: main.cpp PoliticalSys.h Politician.h Party.h Republican.h Leader.h Social.h Democratic.h DemocratSocialPolitician.h DemocratPolitician.h DemocratLeaderPolitician.h RepublicanLeaderPolitician.h RepublicanPolitician.h RepulicanSocialPolitician.h Exception.h
    g++ -c main.cpp

DemocratLeaderPolitician.o: DemocratLeaderPolitician.cpp DemocratLeaderPolitician.h DemocratPolitician.h Politician.h Leader.h
    g++ -c DemocratLeaderPolitician.cpp

DemocratPolitician.o: DemocratPolitician.cpp DemocratPolitician.h Politician.h Democratic.h Party.h
    g++ -c DemocratPolitician.cpp

DemocratSocialPolitician.o: DemocratSocialPolitician.cpp DemocratSocialPolitician.h DemocratPolitician.h Politician.h Social.h
    g++ -c DemocratSocialPolitician.cpp

Democratic.o: Democratic.cpp Democratic.h Party.h Politician.h
    g++ -c Democratic.cpp

Leader.o: Leader.cpp Leader.h Politician.h Party.h
    g++ -c Leader.cpp

Party.o: Party.cpp Party.h Politician.h
    g++ -c Party.cpp

PoliticalSys.o: PoliticalSys.cpp PoliticalSys.h Politician.h Party.h Republican.h Leader.h Social.h Democratic.h DemocratSocialPolitician.h DemocratPolitician.h DemocratLeaderPolitician.h RepublicanLeaderPolitician.h RepublicanPolitician.h RepulicanSocialPolitician.h Exception.h
    g++ -c PoliticalSys.cpp

Politician.o: Politician.cpp Politician.h Party.h
    g++ -c Politician.cpp

Republican.o: Republican.cpp Republican.h Party.h Politician.h
    g++ -c Republican.cpp

RepublicanLeaderPolitician.o: RepublicanLeaderPolitician.cpp RepublicanLeaderPolitician.h RepublicanPolitician.h Politician.h Leader.h
    g++ -c RepublicanLeaderPolitician.cpp

RepublicanPolitician.o: RepublicanPolitician.cpp RepublicanPolitician.h Politician.h Republican.h Party.h
    g++ -c RepublicanPolitician.cpp

RepulicanSocialPolitician.o: RepulicanSocialPolitician.cpp RepulicanSocialPolitician.h RepublicanPolitician.h Politician.h Social.h
    g++ -c RepulicanSocialPolitician.cpp

Social.o: Social.cpp Social.h Politician.h Party.h
    g++ -c Social.cpp

clean :
    rm -f *.o Run
    echo Clean done
