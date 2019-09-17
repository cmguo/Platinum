using Platinum;
using System;
using System.Linq;

namespace Platinum.Managed.MediaServerTest
{
    class Program2
    {

        private MediaRenderer server;
        private Service avt;

        internal void Run()
        {
            log4net.Config.BasicConfigurator.Configure();

            System.Console.Title = "Press 'q' to quit";

            System.Console.WriteLine("Starting...");

            using (var upnp = new UPnP())
            {
                server = new MediaRenderer("TestMediaRenderer", (UInt16)1569);
                server.GetCurrentConnectionInfo += Server_GetCurrentConnectionInfo;
                server.SetAVTransportURI += Server_SetAVTransportURI;
                server.Play += Server_Play;
                server.Pause += Server_Pause;
                server.Seek += Server_Seek;
                server.Stop += Server_Stop;
                
                upnp.AddDeviceHost(server);

                upnp.Start();

                avt = server.Services.Where(s => s.ServiceType == "urn:schemas-upnp-org:service:AVTransport:1").FirstOrDefault();

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

        private int Server_GetCurrentConnectionInfo(Action action)
        {
            return 0;
        }

        private int Server_SetAVTransportURI(Platinum.Action action)
        {
            var uri = action.GetArgumentValue("CurrentURI");
            var meta = action.GetArgumentValue("CurrentURIMetadata");
            avt.FindStateVariable("TransportState").ValueString = "STOPPED";

            avt.FindStateVariable("NumberOfTracks").ValueString = "";
            //avt.FindStateVariable("CurrentMediaDuration");
            avt.FindStateVariable("AVTransportURI").ValueString = uri;
            avt.FindStateVariable("AVTransportURIMetadata").ValueString = meta;
            return 0;
        }

        private int Server_Play(Platinum.Action action)
        {
            avt.FindStateVariable("TransportState").ValueString = "PLAYING";
            return 0;
        }

        private int Server_Pause(Action action)
        {
            avt.FindStateVariable("TransportState").ValueString = "PAUSED_PLAYBACK";
            return 0;
        }

        private int Server_Seek(Platinum.Action action)
        {
            return 0;
        }

        private int Server_Stop(Platinum.Action action)
        {
            avt.FindStateVariable("TransportState").ValueString = "STOPPED";
            return 0;
        }

    }
}
