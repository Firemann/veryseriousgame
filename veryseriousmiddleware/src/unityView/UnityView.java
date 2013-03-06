package unityView;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;

import vsm.VSMiddleware;
import vsm.VSVector3;
import vsm.component.VSTransformPrx;
import vsm.network.VSUnityClientPrx;

@SuppressWarnings("serial")
public class UnityView extends JFrame {
	
	private final static float MOVE = 20.f;

	VSUnityClientPrx unityClientPrx;
	VSTransformPrx transformPrx;
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
		JButton upButton = new JButton("Up");
		upButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				SwingUtilities.invokeLater(new Runnable() {
					
					@Override
					public void run() {
						transformPrx.translate(new VSVector3(0, 0, MOVE));
					}
				});
			}
		});
		mainPanel.add(upButton);
		mainPanel.add(new JPanel());
		JButton leftButton = new JButton("Left");
		leftButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				SwingUtilities.invokeLater(new Runnable() {
					
					@Override
					public void run() {
						transformPrx.translate(new VSVector3(-MOVE, 0, 0));
					}
				});
			}
		});
		mainPanel.add(leftButton);
		JButton downButton = new JButton("Down");
		downButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				SwingUtilities.invokeLater(new Runnable() {
					
					@Override
					public void run() {
						transformPrx.translate(new VSVector3(0, 0, -MOVE));
					}
				});
			}
		});
		mainPanel.add(downButton);
		JButton rightButton = new JButton("Right");
		rightButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				SwingUtilities.invokeLater(new Runnable() {
					
					@Override
					public void run() {
						transformPrx.translate(new VSVector3(MOVE, 0, 0));
					}
				});
			}
		});
		mainPanel.add(rightButton);
		
		this.setContentPane(mainPanel);
		this.setPreferredSize(new Dimension(800, 600));
		this.setVisible(true);
		this.pack();
	}
	public void setProxy(VSUnityClientPrx client) {
		this.unityClientPrx = client;
		transformPrx = unityClientPrx.getTransform();
	}
	
}
