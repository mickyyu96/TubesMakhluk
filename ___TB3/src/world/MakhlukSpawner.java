package world;

import point.Point;
import exception.ExceptionObject;
import randomgenerator.RandomGenerator;

/** Kelas MakhlukSpawner melakukan spawning makhluk secara berkala
 *  @author  Robert Sebastian Herlim / 13514061
 *  @version 1.0
 */
public class MakhlukSpawner implements Runnable {
    public MakhlukSpawner() {
    }
    
    public void spawnFood() {
        int countRabbit = World.getWorldInstance().getObjects().countMakhluk('R');
        int countSheep = World.getWorldInstance().getObjects().countMakhluk('S');
        int countTurtle = World.getWorldInstance().getObjects().countMakhluk('T');
        
        int spawnSelection = RandomGenerator.getInstance().getNextInt(3);
        switch(spawnSelection) {
            case 0:
                if(countRabbit < 2) {
                    WorldBuilder.getBuilderInstance().addAnObject('R');
                }
                break;
            case 1:
                if(countSheep < 2) {
                    WorldBuilder.getBuilderInstance().addAnObject('S');
                }
                break;
            case 2:
                if(countTurtle < 2) {
                    WorldBuilder.getBuilderInstance().addAnObject('T');
                }
                break;
        }
    }
    
    public void spawnEnemy() {
        int countPolarBear = World.getWorldInstance().getObjects().countMakhluk('P');
        int countWolf = World.getWorldInstance().getObjects().countMakhluk('W');
        
        int spawnSelection = RandomGenerator.getInstance().getNextInt(2);
        switch(spawnSelection) {
            case 0:
                if(countPolarBear < 2) {
                    WorldBuilder.getBuilderInstance().addAnObject('P');
                }
                break;
            case 1:
                if(countWolf < 2) {
                    WorldBuilder.getBuilderInstance().addAnObject('W');
                }
                break;
        }
    }
    
    public void run() {
        while (World.getWorldInstance().isEnded() == 0) {
            spawnFood(); spawnEnemy();
        }
    }
}
