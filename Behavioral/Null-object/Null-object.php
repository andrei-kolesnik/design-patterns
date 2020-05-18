<?php
/*
Instead of using a null reference to convey absence of an object, one uses an object which implements the expected interface, but whose method body is empty. 
The advantage of this approach over a working default implementation is that a null object is very predictable and has no side effects: it does nothing.
https://en.wikipedia.org/wiki/Null_object_pattern
*/

abstract class Downloader {
    abstract public function getContents(string $url);
}

// Null-object implementation for the downloader
class NullDownloader extends Downloader {
    public function getContents(string $url)
    {
    }
}

class RegularDownloader extends Downloader {
    public function getContents(string $url)
    {
        print("Getting the contents via the REGULAR protocol from [$url]\n");
    }
}

class SecureDownloader extends Downloader {
    public function getContents(string $url)
    {
        print("Getting the contents via the SECURE protocol from [$url]\n");
    }
}

class DownloaderFactory {
    public function getDownloader(string $url): Downloader
    {
        if (stripos($url, 'HTTPS') !== false)
            return new SecureDownloader();

        if (stripos($url, 'HTTP') !== false)
            return new RegularDownloader();

        return new NullDownloader();
    }
}

$urls = [
    '',
    'not a valid url',
    'http://www.public.com',
    'https://www.private.com',
];

$factory = new DownloaderFactory();
foreach ($urls as $url) {
    $factory->getDownloader($url)->getContents($url); // no need to check whether a downloader is null
}
