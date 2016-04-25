import exception.ExceptionObject;
import inputoutput.Screen;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import world.World;
import world.WorldBuilder;
import world.MakhlukSpawner;
import makhluklive.MakhlukManager;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import java.awt.Component;

/** Kelas Main adalah kelas yang menampung main program.
 *  @author     Micky Yudi Utama / 13514061
 *  @version    1.0
 */
public class Main {
    JButton[] buttons = new JButton[4];
    int showedFrame = 0;
    JTextField[] txtField = new JTextField[3];
    JFrame mainFrame = new JFrame("Main Menu");
    JPanel mainPanel = new JPanel();
    public Main() {
        showMainFrame();
    }
    
    /** fungsi validasi apakah ukuran valid.
     * @param strNBrs string jumlah baris
     * @param strNKol string jumlah kolom
     * @return boolean true jika ukuran valid
     */
     private static boolean isValidUkuran(final String strNBrs,
             final String strNKol) {
        boolean valid = true;
        for (int i = 0; i < strNBrs.length() && valid; i++) {
            if (strNBrs.charAt(i) < '0'
                    || strNBrs.charAt(i) > '9') {
                valid = false;
            }
        }
        for (int i = 0; i < strNKol.length() && valid; i++) {
            if (strNKol.charAt(i) < '0'
                    || strNKol.charAt(i) > '9') {
                valid = false;
            }
        }
        return valid;
     }
     
     private static boolean isValidID(final String s) {
        boolean found = false;
        for (int i = 0; i < s.length() && !found; i++) {
            if (s.charAt(i) != 'P' && s.charAt(i) != 'G' && s.charAt(i) != 'R'
                    && s.charAt(i) != 'T' && s.charAt(i) != 'S'
                    && s.charAt(i) != 'W' && s.charAt(i) != 'U') {
                found = true;
             }
        }
        return !found;
    }
     
    public final void showMainFrame() {
        mainFrame.setVisible(true);
        mainFrame.setSize(724, 600);
        mainFrame.setLocation(295,50);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        JLabel testLabel = new JLabel("", JLabel.CENTER);
        
        ImageIcon image = new ImageIcon(((new ImageIcon("BackgroundMain.png")).
                getImage()).getScaledInstance(724, 600, java.awt.Image.
                SCALE_SMOOTH));
       
        testLabel.setIcon(image);
             
        ImageIcon buttonIcon1 = new ImageIcon(((new ImageIcon
                ("buttonAVMain.png")).getImage()).getScaledInstance(273, 80, 
                java.awt.Image.SCALE_SMOOTH));
        ImageIcon buttonIcon1Clicked = new ImageIcon(((new ImageIcon
                ("buttonAVMainClicked.png")).getImage()).getScaledInstance(273, 
                80, java.awt.Image.SCALE_SMOOTH));
        buttons[0] = new JButton(buttonIcon1);
        buttons[0].setBorder(BorderFactory.createEmptyBorder());
        buttons[0].setContentAreaFilled(false);
        buttons[0].setSize(273, 80);
        buttons[0].setLocation(75, 270);
        buttons[0].addMouseListener(new java.awt.event.MouseAdapter() {
        public void mouseEntered(java.awt.event.MouseEvent evt) {
            buttons[0].setIcon(buttonIcon1Clicked);
        }
        public void mouseExited(java.awt.event.MouseEvent evt) {
            buttons[0].setIcon(buttonIcon1);
        }
        });
        //buttons[0].addMouseMotionListener(this);
        buttons[0].addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                showedFrame = 1;
                showFrame1();
            }
        });
        ImageIcon buttonIcon2 = new ImageIcon(((new ImageIcon
                ("buttonSnakeMain.png")).getImage()).getScaledInstance(273, 80, 
                java.awt.Image.SCALE_SMOOTH));
        ImageIcon buttonIcon2Clicked = new ImageIcon(((new ImageIcon
                ("buttonSnakeMainClicked.png")).getImage()).getScaledInstance
                (273, 80, java.awt.Image.SCALE_SMOOTH));
        buttons[1] = new JButton(buttonIcon2);
        buttons[1].setBorder(BorderFactory.createEmptyBorder());
        buttons[1].setContentAreaFilled(false);
        buttons[1].setSize(273, 80);
        buttons[1].setLocation(75, 370);
        buttons[1].addMouseListener(new java.awt.event.MouseAdapter() {
        public void mouseEntered(java.awt.event.MouseEvent evt) {
            buttons[1].setIcon(buttonIcon2Clicked);
        }
        public void mouseExited(java.awt.event.MouseEvent evt) {
            buttons[1].setIcon(buttonIcon2);
        }
        });
        buttons[1].addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                World.getWorldInstance().setSnakeWorld(1);
                showFrame1();
            }
        });
        mainPanel.add(testLabel);
        mainFrame.add(buttons[0]);
        mainFrame.add(buttons[1]);
        mainFrame.add(mainPanel);
        mainFrame.pack();
        //mainFrame.validate();
    }
    
    public final void showFrame1(){
        
        JPanel panel1 = new JPanel();
        JFrame subFrame1 = new JFrame("");
        subFrame1.setVisible(true);
        subFrame1.setLocation(520,250);
        panel1.setLayout(new BoxLayout(panel1, BoxLayout.Y_AXIS));
        //subFrame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JLabel label1 = new JLabel("Kolom");
        JLabel label2 = new JLabel("Baris");
        JLabel label3 = new JLabel("Makhluk");
        txtField[0] = new JTextField(5);
        txtField[0].setBounds(70,30,150,20);
        
        txtField[1] = new JTextField(5);
        txtField[1].setLocation(100, 200);
        
        txtField[2] = new JTextField(20);
        txtField[2].setLocation(100, 300);
        ImageIcon buttonIcon2 = new ImageIcon(((new ImageIcon("buttonRun.png")).
                getImage()).getScaledInstance(171, 50, java.awt.Image.
                SCALE_SMOOTH));
        ImageIcon buttonIcon2Clicked = new ImageIcon(((new ImageIcon
                ("buttonRunClicked.png")).getImage()).getScaledInstance(171, 50,
                java.awt.Image.SCALE_SMOOTH));
        buttons[2] = new JButton(buttonIcon2);
        buttons[2].setBorder(BorderFactory.createEmptyBorder());
        buttons[2].setContentAreaFilled(false);
        buttons[2].setSize(171, 50);
        buttons[2].setLocation(300,300);
        buttons[2].addMouseListener(new java.awt.event.MouseAdapter() {
        public void mouseEntered(java.awt.event.MouseEvent evt) {
            buttons[2].setIcon(buttonIcon2Clicked);
        }
        public void mouseExited(java.awt.event.MouseEvent evt) {
            buttons[2].setIcon(buttonIcon2);
        }
        });
        buttons[2].addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int nBrs=0, nKol = 0;
                String nBrsString = txtField[0].getText();
                String nKolString = txtField[1].getText();
                String input = txtField[2].getText();
                try {
                    if (!isValidUkuran(nBrsString, nKolString)) {
                        throw new ExceptionObject(4);
                    }

                    nBrs = Integer.parseInt(nBrsString);
                    nKol = Integer.parseInt(nKolString);

                    if (nBrs < 7 || nKol < 7) {
                        throw new ExceptionObject(0);
                    }
                } catch (ExceptionObject ep) {
                    ep.displayErrorMessage();
                    txtField[0].setText("");
                    txtField[1].setText("");
                }
                
                try {
                    playWorld(nBrs, nKol, input);
                } catch (InterruptedException ex) {
                }
            }
        });
        
        
        ImageIcon buttonIcon1 = new ImageIcon(((new ImageIcon
                ("buttonCancel.png")).getImage()).getScaledInstance(171, 50, 
                java.awt.Image.SCALE_SMOOTH));
        ImageIcon buttonIcon1Clicked = new ImageIcon(((new ImageIcon
                ("buttonCancelClicked.png")).getImage()).getScaledInstance(171, 
                50, java.awt.Image.SCALE_SMOOTH));
        buttons[3] = new JButton(buttonIcon1);
        buttons[3].setBorder(BorderFactory.createEmptyBorder());
        buttons[3].setContentAreaFilled(false);
        buttons[3].setSize(171, 50);
        buttons[3].setLocation(600,300);
        buttons[3].addMouseListener(new java.awt.event.MouseAdapter() {
        public void mouseEntered(java.awt.event.MouseEvent evt) {
            buttons[3].setIcon(buttonIcon1Clicked);
        }
        public void mouseExited(java.awt.event.MouseEvent evt) {
            buttons[3].setIcon(buttonIcon1);
        }
        });
        buttons[3].addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            subFrame1.setVisible(false); //you can't see me!
            subFrame1.dispose();
            }
        });
        
        panel1.add(label1);
        panel1.add(txtField[0]);
        panel1.add(label2);
        panel1.add(txtField[1]);
        panel1.add(label3);
        panel1.add(txtField[2]);
        panel1.add(buttons[2]);
        panel1.add(buttons[3]);
        panel1.setAlignmentY(Component.CENTER_ALIGNMENT);
        subFrame1.add(panel1);
        subFrame1.pack();
    }
    public final void playWorld(int nBrs, int nKol, String input) throws 
            InterruptedException {

        World.getWorldInstance().setNBrs(nBrs + 2);
        World.getWorldInstance().setNKol(nKol + 2);
        if (World.getWorldInstance().isSnakeWorld() == 0) {
            WorldBuilder.getBuilderInstance().setStrMakhluk(input);
            WorldBuilder.getBuilderInstance().buildWorldObject();
        } else {
            WorldBuilder.getBuilderInstance().addAnObject('U');
        }

        Thread viewThread = new Thread(new Screen());
        viewThread.start();
        Thread liveThread = new Thread(new MakhlukManager());
        liveThread.start();
        if (World.getWorldInstance().isSnakeWorld() == 1) {
            Thread spawnerThread = new Thread(new MakhlukSpawner());
            spawnerThread.start();
        }
    }

    public final void showFrame2() {
        JFrame subFrame1 = new JFrame("Frame2");
        subFrame1.setVisible(true);
        subFrame1.setSize(600, 400);
        subFrame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel subPanel1 = new JPanel();
        subPanel1.setBackground(Color.BLUE);

        JTextField subTextField1 = new JTextField(20);
        subTextField1.setLocation(100, 100);

        JTextField subTextField2 = new JTextField(20);
        subTextField1.setLocation(100, 200);
        JButton subButton1 = new JButton("Run");
        subButton1.setSize(150,50);
        subButton1.setLocation(100,300);
        subButton1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String nBrsString = subTextField1.getText();
                String nKolString = subTextField2.getText();

                int nBrs = Integer.parseInt(nBrsString);
                int nKol = Integer.parseInt(nKolString);

                try {
                    playWorld(nBrs, nKol, "");
                } catch (InterruptedException ex) {
                }
            }

        });

        subPanel1.add(subButton1);
        subPanel1.add(subTextField1);
        subPanel1.add(subTextField2);
        subFrame1.add(subPanel1, BorderLayout.CENTER);
    }

    public static void main(String[] args) {
        Main M = new Main();
    }
}
