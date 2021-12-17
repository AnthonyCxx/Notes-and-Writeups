
# Interfaces in C#
"An interface is a type definition similar to a class, except that it purely represents a contract between an object and its user. \[An interface\] cannot be directly instantiatied as an object, nor can its data members be defined. So, an interface is nothing but a collection of method and property declarations." 
\- Bobby Davis, Jr. ([video ref](https://www.youtube.com/watch?v=_zCR1Rq7qB0))

Essentially, an interface is a contract that states that any class that inherits from it must implement all of the members of the interface. However, it does not 
specify how. Per convention, the name of an interface should *always* begin with an 'I' (just like private fields should always start with an underscore). Below is an example
of how to use interfaces in a project.

# Full Example of How to Use Interfaces

## MediaFile.cs
```C#
namespace Media
{
    namespace MediaContent
    {
        public abstract class MediaFile
        {
            //Fields
            private readonly string? _name;  //Name of the file
            private readonly ulong _size;  //Size (in bytes, set+displayed in Mebibytes (MiB))

            //Properties
            public string? Name
            {
                get { return _name;}

                init { 
                        if (String.IsNullOrWhiteSpace(value))
                            throw new ArgumentException($"{nameof(value)} cannot be null nor whitespace");

                        _name = value;
                }
            }
            public ulong Size
            {
                //1,048,576 bytes = 1 Mebibyte (1024 Kibibytes = 1024*1024 Bytes)
                get  { return _size / 1_048_576; }
                init { _size = value * 1_048_576; }
            }

            //Constructor
            public MediaFile(string name, ulong size = 0)
            {
                Name = name;     
                Size = size;
            }
        }
    }
}
```

## IPlayable.cs
```C#
namespace Media
{
    namespace MediaContent
    {
        interface IPlayable
        {
            public uint Duration {get; init;}  //Length (in seconds)
            public uint CurrentPoint {get; protected set;} //Current point on the content (in seconds)

            //Methods for manipulating playable content
            void Play();
            void Pause();
            void Rewind(uint seconds);
            void FastForward(uint seconds);
            void ToBeginning();
            void ToEnd();       
        }
    }
}
```

## Video.cs
```C#
namespace Media
{
    namespace MediaContent
    {
        public class Video: MediaFile, IPlayable
        {
            //Structure for video resolution
            public readonly struct Resolution
            {
                //Properties
                public readonly uint HorizontalPixels {get; init;}
                public readonly uint VerticalPixels {get; init;}

                //Constructor
                public Resolution(uint horizontalPixels, uint verticalPixels)
                {
                    HorizontalPixels = horizontalPixels;
                    VerticalPixels = verticalPixels;
                }

                //Methods
                public override string ToString() => $"{HorizontalPixels}x{VerticalPixels}";
            }


            //Properties
            Resolution VideoResultion{get; init;}
            public uint Duration {get; init;}
            public uint CurrentPoint{get; set;}


            //Constructor
            public Video(string name, ulong size, uint duration, uint horizontalPixels, uint verticalPixels): base(name, size)
            {
                Duration = duration;
                CurrentPoint = 0;
                VideoResultion = new Resolution(horizontalPixels, verticalPixels);
            }

            //IPlayable Methods
            public void Play()
            {
                Console.WriteLine("Playing the video!");
            }

            public void Pause()
            {
                Console.WriteLine("Pausing the video!");
            }

            public void Rewind(uint seconds)
            {
                CurrentPoint -= seconds;
            }

            public void FastForward(uint seconds)
            {
                CurrentPoint += seconds;
            }

            public void ToBeginning()
            {
                CurrentPoint = 0;
            }

            public void ToEnd()
            {
                CurrentPoint = Duration;
            }
        }
    }
}
```


## Main.cs
```C#
using System;
using Media.MediaContent;

namespace Prog
{
    public class Program
    {
        public static void Main(string[] args)
        {   
            //Crete a new video: title, size, duration, resolution (HxV)
            var video = new Video("Tacones Rojos", 1024, 180, 1280, 720);
            video.Play();
            video.Pause();
        }
    }
}
```
