package unityView;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

import vsm.VSMiddleware;

@SuppressWarnings("serial")
public class UnityView extends JFrame {

	public UnityView() {
		this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		this.addWindowListener(new WindowAdapter() {
			
			@Override
			public void windowClosing(WindowEvent arg0) {
				VSMiddleware.communicator().shutdown();
			}
			
		});
		
		JPanel mainPanel = new JPanel(new GridLayout(3, 3));
		mainPanel.add(new JPanel());
		mainPanel.add(new JPanel());
		mainPanel.add(new JPanel());
		mainPanel.add(new JPanel());
		mainPanel.add(new JButton("Up"));
		mainPanel.add(new JPanel());
		mainPanel.add(new JButton("Left"));
		mainPanel.add(new JButton("Down"));
		mainPanel.add(new JButton("Right"));
		
		this.setContentPane(mainPanel);
		this.setPreferredSize(new Dimension(800, 600));
		this.setVisible(true);
		this.pack();
	}
	
}
