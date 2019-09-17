using Platinum;

namespace Platinum.Managed.MediaServerTest
{
    class Program2
    {
        internal void Run()
        {
            log4net.Config.BasicConfigurator.Configure();

            System.Console.Title = "Press 'q' to quit";

            System.Console.WriteLine("Starting...");

            using (var upnp = new UPnP())
            {
                var server = new Platinum.MediaRenderer("TestMediaRenderer");
                server.SetAVTransportURI += Server_SetAVTransportURI;
                server.Play += Server_Play;
                server.Pause += Server_Pause;
                server.Seek += Server_Seek;
                server.Stop += Server_Stop;
                
                upnp.AddDeviceHost(server);

                upnp.Start();

                #region handle keyboard

                for (bool quit = false; !quit; )
                {
                    switch (System.Console.ReadKey(true).KeyChar)
                    {
                        case 'q':
                            quit = true;

                            break;
                    }
                }

                #endregion

                upnp.Stop();
            }

            System.Console.WriteLine("Stopped.");
        }

        private int Server_SetAVTransportURI(Platinum.Action action)
        {
            return 0;
        }

        private int Server_Seek(Platinum.Action action)
        {
            return 0;
        }

        private int Server_Stop(Platinum.Action action)
        {
            return 0;
        }

        private int Server_Pause(Action action)
        {
            return 0;
        }

        private int Server_Play(Platinum.Action action)
        {
            return 0;
        }

    }
}
