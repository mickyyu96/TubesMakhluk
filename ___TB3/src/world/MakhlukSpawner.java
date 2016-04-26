package world;

import randomgenerator.RandomGenerator;

/** Kelas MakhlukSpawner melakukan spawning makhluk secara berkala.
 *  @author  Robert Sebastian Herlim / 13514061
 *  @version 1.0
 */
public class MakhlukSpawner implements Runnable {
    /** Menciptakan sebuah instance dari MakhlukSpawner.
     */
    public MakhlukSpawner() {
    }
    /** Melakukan "spawn" makanan ular dalam singleton World.
     */
    public final void spawnFood() {
        ListMakhluk worldObjects = World.getWorldInstance().getObjects();
        int countRabbit = worldObjects.countMakhluk('R');
        int countSheep = worldObjects.countMakhluk('S');
        int countTurtle = worldObjects.countMakhluk('T');
        int spawnSelection;
        spawnSelection = RandomGenerator.getInstance().getNextInt(3);
        switch (spawnSelection) {
            case 0:
                if (countRabbit < 2) {
                    WorldBuilder.getBuilderInstance().addAnObject('R');
                }
                break;
            case 1:
                if (countSheep < 2) {
                    WorldBuilder.getBuilderInstance().addAnObject('S');
                }
                break;
            case 2:
                if (countTurtle < 2) {
                    WorldBuilder.getBuilderInstance().addAnObject('T');
                }
                break;
        default:
        break;
        }
    }
    /** Melakukan "spawn" enemy ular dalam singleton World.
     */
    public final void spawnEnemy() {
        ListMakhluk worldObjects = World.getWorldInstance().getObjects();
        int countPolarBear = worldObjects.countMakhluk('P');
        int countWolf = worldObjects.countMakhluk('W');
        int spawnSelection = RandomGenerator.getInstance().getNextInt(2);
        switch (spawnSelection) {
            case 0:
                if (countPolarBear < 2) {
                    WorldBuilder.getBuilderInstance().addAnObject('P');
                }
                break;
            case 1:
                if (countWolf < 2) {
                    WorldBuilder.getBuilderInstance().addAnObject('W');
                }
                break;
            default:
                break;
        }
    }
    @Override
    public final void run() {
        while (World.getWorldInstance().isEnded() == 0) {
            spawnFood(); spawnEnemy();
        }
    }
}
