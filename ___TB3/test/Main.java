import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

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
        
        
        
        ImageIcon image = new ImageIcon(((new ImageIcon("test.jpg")).getImage()).getScaledInstance(470, 702, java.awt.Image.SCALE_SMOOTH));
       
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
    
    public final void showFrame1() {
        JFrame mainFrame = new JFrame("Frame1");
        mainFrame.setVisible(true);
        mainFrame.setSize(600, 400);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        JPanel mainPanel = new JPanel();
        mainPanel.setBackground(Color.RED);
        
        JButton mainButton = new JButton("Test");
        
        JLabel mainLabel = new JLabel("Main Menu", JLabel.CENTER);
        
        mainPanel.add(mainButton);
        mainPanel.add(mainLabel);
        mainFrame.add(mainPanel, BorderLayout.CENTER);
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
