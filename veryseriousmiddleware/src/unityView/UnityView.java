package unityView;

import java.awt.BorderLayout;
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

import vsm.VSDirection;
import vsm.VSMiddleware;
import vsm.unity.VSSoldierPrx;
import vsm.unity.VSUnityClientPrx;

@SuppressWarnings("serial")
public class UnityView extends JFrame {
	
	private VSUnityClientPrx unityClientPrx;
	private VSSoldierPrx soldierPrx;
	private UnityMap map;
	
	public UnityView() {
		
		this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		this.addWindowListener(new WindowAdapter() {
			
			@Override
			public void windowClosing(WindowEvent arg0) {
				VSMiddleware.communicator().shutdown();
			}
			
		});
		this.setLayout(new BorderLayout());
		
		this.add(map = new UnityMap(), BorderLayout.CENTER);
		
		JPanel mainPanel = new JPanel(new GridLayout(3, 3));
		mainPanel.add(new JPanel());
		mainPanel.add(new JPanel());
		mainPanel.add(new JPanel());
		mainPanel.add(new JPanel());
		final JButton upButton = new JButton("Up");
		upButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				SwingUtilities.invokeLater(new Runnable() {

					@Override
					public void run() {
						soldierPrx.move(VSDirection.UP);
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
						soldierPrx.move(VSDirection.LEFT);
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
						soldierPrx.move(VSDirection.DOWN);
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
						soldierPrx.move(VSDirection.RIGHT);
					}
				});
			}
		});
		mainPanel.add(rightButton);
		
		this.add(mainPanel, BorderLayout.SOUTH);
		this.setPreferredSize(new Dimension(800, 600));
		this.setVisible(true);
		this.pack();
	}
	public void setProxy(VSUnityClientPrx client) {
		this.unityClientPrx = client;
		soldierPrx = unityClientPrx.instantiateSoldier();
		map.setSoldier(soldierPrx);
	}
	
}
