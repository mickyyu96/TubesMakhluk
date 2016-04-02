import javax.swing.JOptionPane;

class ExceptionObject
{
    private int id;
    private final String messages[] = 
    {
        ">> ERROR! Dimensi ukuran dunia harus > 6!",
        ">> ERROR! Ada ID yang tidak dikenali!",
        ">> ERROR! Pause World dulu sebelum melakukan Single-step Execution!",
        ">> ERROR! Keypress tidak dikenali!"
    };
    
    public ExceptionObject(int _id)
    {
        id = _id;
    }
    
    public void DisplayErrorMessage()
    {
        JOptionPane.showMessageDialog(null, messages[id], "", JOptionPane.INFORMATION_MESSAGE);
    }
}
