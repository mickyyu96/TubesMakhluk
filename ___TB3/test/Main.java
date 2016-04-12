import inputoutput.Screen;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.logging.Logger;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import makhluklive.MakhlukLive;
import world.World;
import world.WorldBuilder;

/** Kelas Main adalah kelas yang menampung main program.
 *  @author     Micky Yudi Utama / 13514061
 *  @version    1.0
 */
public class Main {
    public Main() {
        showMainFrame();
    }
    
    public final void showMainFrame() {
        JFrame mainFrame = new JFrame("Main Menu");
        mainFrame.setVisible(true);
        mainFrame.setSize(600, 600);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        JLabel testLabel = new JLabel("", JLabel.CENTER);
        
        ImageIcon image = new ImageIcon(((new ImageIcon("Animal's Village.jpg")).getImage()).getScaledInstance(470, 702, java.awt.Image.SCALE_SMOOTH));
       
        testLabel.setIcon(image);
        
        JPanel mainPanel = new JPanel();
        
        
        JLabel mainLabel = new JLabel("Main Menu", JLabel.CENTER);
        
        JButton mainButton1 = new JButton("Animal's Village");
        mainButton1.setSize(150, 50);
        mainButton1.setLocation(100, 200);
        mainButton1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                mainFrame.setVisible(false);
                showFrame1();
            }
        });
       
        JButton mainButton2 = new JButton("Snake");
        mainButton2.setSize(150, 50);
        mainButton2.setLocation(100, 300);
        mainButton2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                mainFrame.setVisible(false);
                showFrame2();
            }
        });
        
        mainFrame.add(mainButton1);
        mainFrame.add(mainButton2);
        mainFrame.add(mainLabel);
        mainPanel.add(testLabel);
        mainFrame.add(mainPanel);
        mainFrame.pack();
        //mainFrame.validate();
    }
    
    public final void showFrame1(){
        JFrame subFrame1 = new JFrame("Frame1");
        subFrame1.setVisible(true);
        subFrame1.setSize(600, 400);
        subFrame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        JPanel subPanel1 = new JPanel();
        subPanel1.setBackground(Color.RED);
        
        
        JTextField subTextField1 = new JTextField(20);
        subTextField1.setLocation(100, 100);
        
        JTextField subTextField2 = new JTextField(20);
        subTextField1.setLocation(100, 200);
        
        JTextField subTextField3 = new JTextField(20);
        subTextField1.setLocation(100, 300);
        
        JLabel subLabel1 = new JLabel("1", JLabel.CENTER);
        JLabel subLabel2 = new JLabel("2", JLabel.CENTER);
        JLabel subLabel3 = new JLabel("3", JLabel.CENTER);
        
        JButton subButton1 = new JButton("Run");
        subButton1.setSize(150,50);
        subButton1.setLocation(100,300);
        subButton1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String nBrsString = subTextField1.getText();
                String nKolString = subTextField2.getText();
                String input = subTextField3.getText();
                
                subLabel1.setText(nBrsString);
                subLabel2.setText(nKolString);
                subLabel3.setText(input);
                
                int nBrs = Integer.parseInt(nBrsString);
                int nKol = Integer.parseInt(nKolString);
                
                try {
                    
                    playWorld(nBrs, nKol, input);
                }
                catch (InterruptedException ex) {
                    
                }
            }
            
        });
        
        
        
        subPanel1.add(subButton1);
        subPanel1.add(subLabel1);
        subPanel1.add(subLabel2);
        subPanel1.add(subLabel3);
        subPanel1.add(subTextField1);
        subPanel1.add(subTextField2);
        subPanel1.add(subTextField3);
        subFrame1.add(subPanel1, BorderLayout.CENTER);
    }
    public final void playWorld(int nBrs, int nKol, String input) throws InterruptedException {
        
        World.getWorldInstance().setNBrs(nBrs+2);
        World.getWorldInstance().setNKol(nKol+2);
        WorldBuilder.getBuilderInstance().setStrMakhluk(input);
        WorldBuilder.getBuilderInstance().buildWorldObject();
        Thread viewThread = new Thread(new Screen());
        viewThread.start();
        Thread liveThread = new Thread(new MakhlukLive());
        liveThread.start();
        
    }
    
    /**
     *      SNAKE EDIT DI SINI
     */
    public final void showFrame2() {
        JFrame mainFrame = new JFrame("Frame2");
        mainFrame.setVisible(true);
        mainFrame.setSize(600, 400);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        JPanel mainPanel = new JPanel();
        mainPanel.setBackground(Color.BLUE);
        
        JButton mainButton = new JButton("Test");
        
        JLabel mainLabel = new JLabel("Main Menu", JLabel.CENTER);
        
        mainPanel.add(mainButton);
        mainPanel.add(mainLabel);
        mainFrame.add(mainPanel, BorderLayout.CENTER);
    }
    
    public static void main(String[] args) {
        Main M = new Main();
    }
}
