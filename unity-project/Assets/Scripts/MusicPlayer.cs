using UnityEngine;

public class MusicPlayer : MonoBehaviour

{
    public bool RandomStart = false;
    public AudioClip[] SongList; 

    private int SongNumber = 0;
    private AudioSource Music;
    private float timer;
    private bool play = true;

    void Start()
    {
        Music = gameObject.AddComponent<AudioSource>();
        //Switch to GetComponent if you are fine with using a pre-existing AudioSource
        //Music = gameObject.GetComponent<AudioSource>();

        if(RandomStart)
        {
            SongNumber = Random.Range(0,SongList.Length);
        }

        Music.loop = false;
        Music.playOnAwake = true;

        if(SongList.Length > 0)
        {
            Music.clip = SongList[SongNumber];
        }

        Music.volume = 0.6f;
        Music.audio.Play();
    }
   
    void Update()
    {
        timer = timer + Time.deltaTime;

        if(SongList.Length > 0 && timer > (Music.clip.length + 1) && play == true)
        {
            play = false;
			
            if(SongNumber < (SongList.Length-1))
            {
                SongNumber = SongNumber + 1;
            }

            else
            {
                SongNumber = 0;
            }
           
            Music.clip = SongList[SongNumber];
      
            Music.audio.Play();
            timer = 0;
            play = true;
        }
    }
}