import React from 'react';
import './Sidebar.css';
import SidebarRow from './SidebarRow';
import { ExpandMoreSharp, HistorySharp, HomeSharp, OndemandVideoSharp, SubscriptionsSharp, ThumbUpOutlined, VideoLibrarySharp, WatchLaterSharp, WhatshotSharp } from '@mui/icons-material';

function Sidebar() {
  return (
    <div className='sidebar'>
        <SidebarRow selected Icon={HomeSharp} title="Home"/>
        <SidebarRow Icon={WhatshotSharp} title="Trending"/>
        <SidebarRow Icon={SubscriptionsSharp} title="Subscription"/>
        <hr/>
        <SidebarRow Icon={VideoLibrarySharp} title="Library"/>
        <SidebarRow Icon={HistorySharp} title="History"/>
        <SidebarRow Icon={OndemandVideoSharp} title="Your Videos"/>
        <SidebarRow Icon={WatchLaterSharp} title="Watch Later"/>
        <SidebarRow Icon={ThumbUpOutlined} title="Liked Videos"/>
        <SidebarRow Icon={ExpandMoreSharp} title="Show More"/>
        <hr/>
    </div>
  )
}

export default Sidebar