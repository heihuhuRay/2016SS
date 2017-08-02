package Listener;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Observable;
import java.util.Observer;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import observer.UIObserver;
import storytelling.Storyteller;

/**
 * GUI Class which contains the UIObserver
 * 
 * Shows a simple dialog where the user can select how many stories are told
 * 
 * @author mfrank
 *
 */
public class GUIListener extends JFrame implements UIObserver, ActionListener {

	private final JTextArea textArea;
	private final JTextField input;
	private final JButton tellButton;
	private final SimpleDateFormat df;

	/**
	 * Constructor, that inits the GUI, and registers itself to the observable
	 */
	public GUIListener() {
		super("UI Listener");
		textArea = new JTextArea();
		JPanel inputContainer = new JPanel(new GridLayout(2, 2));
		input = new JTextField();
		tellButton = new JButton("Tell storys");
		tellButton.addActionListener(this);
		inputContainer.add(new JLabel("Storys to tell  (number)"));
		inputContainer.add(input);
		inputContainer.add(new JLabel("Breaks between storys are 0 to 4 sec"));
		inputContainer.add(tellButton);
		this.add(inputContainer, BorderLayout.NORTH);
		this.add(new JScrollPane(textArea), BorderLayout.CENTER);

		this.setSize(new Dimension(600, 300));
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setLocationRelativeTo(null);
		this.setVisible(true);

		df = new SimpleDateFormat("HH:MM:ss");

		// Adds itself to the observable
		Storyteller.getStoryteller().addObserver(this);
	}

	@Override
	public void update(String story) {
		textArea.append(df.format(new Date(System.currentTimeMillis())) + ": " + story + "\n");
		textArea.revalidate();
	}

	@Override
	public void actionPerformed(ActionEvent e) {

		try {
			final int number = Integer.parseInt(input.getText());
			tellButton.setEnabled(false);
			tellButton.setText("telling ...");
			new Thread(new Runnable() {

				@Override
				public void run() {
					Storyteller.getStoryteller().startTelling(number);

				}
			}).start();
		} catch (Exception e2) {
			JOptionPane.showConfirmDialog(this, "please put only numbers in the textfield");
		}

	}

	@Override
	public void workloadDone() {
		tellButton.setEnabled(true);
		tellButton.setText("Tell storys");
		textArea.append("### Done - all storys are told ### \n");
		textArea.revalidate();
	}

}
