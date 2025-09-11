import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Main2100998 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("자신학번 기말고사");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 400);

        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("파일");
        JMenuItem exitMenuItem = new JMenuItem("종료");
        exitMenuItem.addActionListener(e -> System.exit(0));
        fileMenu.add(exitMenuItem);
        menuBar.add(fileMenu);
        frame.setJMenuBar(menuBar);

        JTabbedPane tabbedPane = new JTabbedPane();

        JPanel panel1 = new JPanel(new BorderLayout());

        JLabel infoLabel = new JLabel("작성자 정보 : ", SwingConstants.CENTER);
        infoLabel.setFont(new Font("맑은 고딕", Font.BOLD, 16));
        panel1.add(infoLabel, BorderLayout.NORTH);

        JPanel btnPanel = new JPanel(new GridLayout(1, 2, 10, 0));
        JButton nameBtn = new JButton("이름");
        JButton idBtn = new JButton("학번");

        nameBtn.setFont(new Font("맑은 고딕", Font.BOLD, 15));
        idBtn.setFont(new Font("맑은 고딕", Font.BOLD, 15));

        nameBtn.setPreferredSize(new Dimension(0, 80)); 
        idBtn.setPreferredSize(new Dimension(0, 80));

        nameBtn.addActionListener(e -> infoLabel.setText("작성자 정보 : 이수찬"));
        idBtn.addActionListener(e -> infoLabel.setText("작성자 정보 : 2100998"));

        btnPanel.add(nameBtn);
        btnPanel.add(idBtn);

        panel1.add(btnPanel, BorderLayout.SOUTH);

        panel1.add(Box.createRigidArea(new Dimension(0, 80)), BorderLayout.CENTER);

        tabbedPane.addTab("기능 1", panel1);

        frame.add(tabbedPane);

        frame.setVisible(true);
    }
}
