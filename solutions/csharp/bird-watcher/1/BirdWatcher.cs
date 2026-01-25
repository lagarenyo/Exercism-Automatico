using System;
using System.Linq;

class BirdCount
{
    private int[] birdsPerDay;
    public BirdCount(int[] birdsPerDay)
    {
        this.birdsPerDay = birdsPerDay;
    }


    public static int[] LastWeek() => new[] { 0, 2, 5, 3, 7, 8, 4 };

    public int Today() => birdsPerDay[6];

    public void IncrementTodaysCount() => birdsPerDay[6]++;

    public bool HasDayWithoutBirds()
    {
        bool res = false;
        foreach (var item in this.birdsPerDay)
            res = (item == 0) ? true : res;
        return res;
    }

    public int CountForFirstDays(int numberOfDays)
    {
        int res = 0;
        for (int i = 0; i < numberOfDays; i++)
            res += birdsPerDay[i];
        return res;
    }

    public int BusyDays()
    {
        int res = 0;
        foreach (var item in birdsPerDay)
            res += item > 4 ? 1 : 0;
        return res;
    }
}