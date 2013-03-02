package slide2GUI;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

import net.miginfocom.swing.MigLayout;

@SuppressWarnings("serial")
public class Slide2GUI extends JFrame {
	
	public class LogStreamReader implements Runnable {

	    private BufferedReader reader;
	    private StringBuilder sb;

	    public LogStreamReader(InputStream is) {
	        this.reader = new BufferedReader(new InputStreamReader(is));
	        this.sb = new StringBuilder();
	    }

	    public void run() {
	        try {
	            String line = reader.readLine();
	            while (line != null) {
	                sb.append(line + "\n");
	                line = reader.readLine();
	            }
	            reader.close();
	        } catch (IOException e) {
	            e.printStackTrace();
	        }
	    }
	    
	    public String toString() {
	    	return sb.toString();
	    }
	}
	
	public static void main(String... args) {
		new Slide2GUI();
	}

	public enum Extension {
		CPP("slice2cpp"), JAVA("slice2java"), CSHARP("slice2cs"), PHP("slide2php"), PYTHON("slide2py"); 
		
		private String path;
		
		Extension(String path) {
			this.path = path;
		}
		
		public String getProgramName() {
			return path;
		}
	}
	
	public static final String ICE_EXTENSION = "ice";
	
	private JTextField sourceField;
	private JTextField destinationField;
	private JTextField iceField;
	private JComboBox<Extension> extensionComboBox;

	public Slide2GUI() {
		initialize();
		
		this.setTitle("Slide2GUI - Convert Ice files easily");
		
		JPanel mainPanel = new JPanel();
		mainPanel.setLayout(new MigLayout());
		
		mainPanel.add(new JLabel("Slice Path :"));
		iceField = new JTextField(20);
		mainPanel.add(iceField);
		JButton iceChooseButton = new JButton("...");
		iceChooseButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				File f = chooseDirectory();
				if(f!=null)
					iceField.setText(f.getAbsolutePath());
			}
		});
		mainPanel.add(iceChooseButton, "wrap");
		
		mainPanel.add(new JLabel("Convert to :"));
		extensionComboBox = new JComboBox<>(Extension.values());
		mainPanel.add(extensionComboBox, "wrap");
		
		mainPanel.add(new JLabel("Source Path (recursively) :"));
		sourceField = new JTextField(20);
		mainPanel.add(sourceField);
		JButton sourceChooseButton = new JButton("...");
		sourceChooseButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				File f = chooseDirectory();
				if(f!=null)
					sourceField.setText(f.getAbsolutePath());
			}
		});
		mainPanel.add(sourceChooseButton, "wrap");
		
		mainPanel.add(new JLabel("Destination Path :"));
		destinationField = new JTextField(20);
		mainPanel.add(destinationField);
		JButton destinationChooseButton = new JButton("...");
		destinationChooseButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				File f = chooseDirectory();
				if(f!=null)
					destinationField.setText(f.getAbsolutePath());
			}
		});
		mainPanel.add(destinationChooseButton, "wrap");
		
		JButton compileButton = new JButton("Run !");
		compileButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				compile();
			}
		});
		mainPanel.add(compileButton, "wrap");
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setContentPane(mainPanel);
		this.pack();
		this.setResizable(false);
		this.setVisible(true);
	}
	
	public void initialize() {
		//TODO : read default config from a file
	}
	
	public void compile() {
		List<String> parameters = new LinkedList<String>();
		
		ProcessBuilder b = new ProcessBuilder(parameters);
		b.redirectErrorStream(true);
		
		// Program
		String program = new File(iceField.getText()).getAbsolutePath() + File.separator + extensionComboBox.getItemAt(extensionComboBox.getSelectedIndex()).getProgramName() + ".exe";
		parameters.add(program);
		
		// Destination Folder
		parameters.add("--output-dir");
		parameters.add(destinationField.getText());
		
		// Include path = source folder
		parameters.add("-I");
		parameters.add(sourceField.getText());
		
		// Sources files
		parameters.addAll(getRecursiveIceFile(sourceField.getText()));

		try {
			Process process = b.start();
			LogStreamReader lsr = new LogStreamReader(process.getInputStream());
			Thread thread = new Thread(lsr);
			thread.start();
			
			if(process.waitFor() == 0) {
				JOptionPane.showMessageDialog(this, "Done !", "Slide2GUI - Information", JOptionPane.INFORMATION_MESSAGE);
			}
			else {
				JOptionPane.showMessageDialog(this, lsr.toString(), "Slide2GUI - Error", JOptionPane.ERROR_MESSAGE);
			}
		} catch (IOException e) {
			JOptionPane.showMessageDialog(this, e.getMessage(), "Slide2GUI - Error", JOptionPane.ERROR_MESSAGE);
		} catch (InterruptedException e) {
			JOptionPane.showMessageDialog(this, e.getMessage(), "Slide2GUI - Error", JOptionPane.ERROR_MESSAGE);
		}
	}
	
	public List<String> getRecursiveIceFile(String source) {
		List<String> files = new LinkedList<>();
		walkRecursiveIceFile(new File(source), files);
		return files;
	}
	
	private void walkRecursiveIceFile(File root, List<String> files) {
		File[] list = root.listFiles();
		if(list!=null) {
			for(File f:list) {
				if(f.isDirectory()) {
					walkRecursiveIceFile(f, files);
				}
				else {
					int i = f.getName().lastIndexOf('.');
					if (i > 0) {
					    String extension = f.getName().substring(i+1).toLowerCase();
					    if(extension.equals(ICE_EXTENSION))
					    	files.add(f.getAbsolutePath());
					}
				}
			}
		}
	}
	
	private File chooseDirectory() {
		JFileChooser jfc = new JFileChooser();
		jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
		int returnValue = jfc.showOpenDialog(this);
		if(returnValue == JFileChooser.APPROVE_OPTION) {
			return jfc.getSelectedFile();
		}
		return null;		
	}
	
}
