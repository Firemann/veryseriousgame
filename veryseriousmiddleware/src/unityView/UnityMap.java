package unityView;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Timer;
import java.util.TimerTask;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

import vsm.VSVector3;
import vsm.unity.VSSoldierPrx;

@SuppressWarnings("serial")
public class UnityMap extends JPanel {

	private BufferedImage map;
	private VSSoldierPrx soldier;
	
	public UnityMap() {
		
		// Map
		try {
			map = ImageIO.read(this.getClass().getResource("map.png"));
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
	}
	
	@Override
	protected void paintComponent(Graphics g) {
		Graphics2D g2d = (Graphics2D) g;
		g2d.drawImage(map, 0, 0, null);
		if(soldier!=null) {
			Point p = getSoldierPosition(soldier);
			g2d.setColor(Color.RED);
			g2d.fillRect(p.x-6, p.y-6, 12, 12);
		}
	}
	
	private Point getSoldierPosition(VSSoldierPrx soldier) {
		VSVector3 pos = soldier.getPosition();
//		System.out.println("[" + pos.x + "," + pos.y + "," + pos.z + "]" );
		return new Point((int) Math.round(pos.x * 1.132 + 120), (int) (Math.round(-pos.z * 1.132) + 886));
	}
	
	public void setSoldier(VSSoldierPrx soldier) {
		this.soldier = soldier;
		if(soldier!=null) {
			Timer t = new Timer();
			t.schedule(new TimerTask() {
				
				@Override
				public void run() {
					repaint();
				}
			}, 0, 100);
		}
	}
	
}
